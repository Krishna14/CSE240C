# CSE 240C
Advanced Microarchitecture - Contributions related to the micro-architectural reverse engineering of modern processors.

### Instructions for homework 1

To run the code, please run ./latencyComputation.o. If you choose to compile from src, please run the following command

g++ -o latencyComputation.o latencyComputation.cpp

That will generate the latencyComputation.o which could later be run. 

This only supports latency computation on those processors that have a 64 byte cache line size.

Support for other cache line sizes will be extended by tomorrow.

### Instructions for homework 2

In this assignment, we attempt to reverse engineer specific aspects of the Microarchitecture of any Superscalar OoO processor.
The following steps are used to generate the files needed to test the values generated by the code -

1. Generate the extended asm file. Based on the architecture that needs to be tested, we generate the different forms of asm code.
2. There are primarily two variants of that code. One is for Visual Studio and the other is GCC compatible (that runs on Linux kernel).
3. The current version only supports GCC asm code. I will add more support for the Linux Kernel in the near future.
