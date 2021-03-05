#!/bin/python3

import subprocess
import time
import os
from collections import defaultdict

# Initializing the value of timeout = 120 seconds
timeout = 120

# Compile the cpp to generate the different files for reverse engineering the BPU
compilationCmd = "g++ -o write_assembly_program.o write_assembly_program.cpp -g"
proc = subprocess.Popen(compilationCmd.split(),stdin=subprocess.PIPE,stdout=subprocess.PIPE,stderr=subprocess.PIPE)
try:
    (out, err) = proc.communicate(timeout=timeout)
except:
    print("Timeout exception for write_assembly_program compilation")
    (out, err) = proc.communicate()

# print(out)

branches = [2**i for i in range(7, 13)]
# print("Branches = {}".format(branches))
distances = [2**i for i in range(1, 7)]
# print("Distances = {}".format(distances))

runTimeMap = defaultdict(float)

for branch in branches:
    for distance in distances:
        dist, br = str(distance), str(branch)
        fileName = "btb_trial" + '_' + dist + '_' + br
        sourceFileCmd = "./write_assembly_program.o --num_iter 1000000 --distance " + dist + " --num_branches " + br + " --file_name " + str(fileName) + ".cpp"
        print("File generation command = {}".format(sourceFileCmd))
        # Opened the subprocess and have generated a few files to provide more gains in perf
        proc_compile = subprocess.Popen(sourceFileCmd.split(), stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        try:
            (out_compile, err_compile) = proc_compile.communicate(timeout=timeout)
        except TimeoutExpired:
            # Here, we kill a process if it times out
            proc_compile.kill()
            (out_compile, err_compile) = proc_compile.communicate()

        if(os.path.isfile("./"+fileName+".cpp")):
            compileCmd = "g++ -o " + fileName + ".o " + fileName + ".cpp"
            proc_src = subprocess.Popen(compileCmd.split(), stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            # Here, we create the "proc_src"
            try:
                (out_src, err_src) = proc_src.communicate(timeout=timeout)
            except TimeoutExpired:
                proc_src.kill()
                (out_src, err_src) = proc_src.communicate()
            # TODO: Error checking for every command that's called
            # Start time
            if(os.path.isfile("./"+fileName+".o")):
                startTime = time.time_ns()
                perfCmd = "./" + fileName + ".o"
                proc_run = subprocess.Popen(perfCmd.split(), stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                try:
                    (out_run, err_run) = proc_run.communicate()
                    endTime = time.time_ns()
                except TimeoutExpired:
                    proc_run.kill()
                    (out_run, err_run) = proc_run.communicate()
                
                runTime = (endTime - startTime) / (10 ** 9)
                print("Runtime @ branch = {}, distance = {} is {}".format(branch, distance, runTime))
                key = str(branch) + '_' + str(distance)
                runTimeMap[key] = runTime
            else:
                print("File {} not present\n".format("./"+fileName+".o"))
                exit()
        else:
            print("File {} not present\n".format("./"+fileName+".cpp"))
            exit()
