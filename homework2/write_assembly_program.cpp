#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define A_FATAL(a, b) { if (!(a)) { cout << b << endl; exit(0); } }

int main(int argc, char* argv[])
{
    uint32_t iterations;
    int distance;
    int branches;
    string file_name;
    ofstream outfile;
    int m;
    int num_mov, num_cmp, num_clc;
    
    if(argc < 9)
    {
        cout << "USAGE: ./write_assembly_program.o --num_iter 20 --distance 2 ";
        cout << "--num_branches 100 --file_name <>.cpp \n";
        exit(0);
    }
    else
    {
        for(int i=1;i<argc;i++)
        {
            if(!strcmp(argv[i], "--num_iter"))
                iterations = atoi(argv[i+1]);
            else if(!strcmp(argv[i], "--distance"))
                distance = atoi(argv[i+1]);
            else if(!strcmp(argv[i], "--num_branches"))
                branches = atoi(argv[i+1]);
            else if(!strcmp(argv[i], "--file_name"))
                file_name = argv[i+1];
        }

        m = iterations / 1000000;
        A_FATAL(iterations % 1000000 == 0, "Number of iterations should be in millions \n");
    }
    cout << "Input file name is: " << file_name << "\n";
    outfile.open(file_name.c_str(), std::fstream::out);
    outfile  << "#include <iostream> \n";
    outfile  << "using namespace std; \n";
    outfile  << "int main(void) {\n";
    outfile  << "uint64_t i;\n";
    outfile  << "uint64_t iter = " << iterations << ";\n";
    outfile  << "for (i=0; i < iter; i++) {\n";
    outfile  << "__asm__ (\n";
    //	distance = (distance - 2);
    num_mov = (distance / 5);
    num_cmp = (distance % 5) / 3;
    num_clc = (distance % 5) % 3;
    outfile << "\"clc\\n\"\n";
    outfile << "\"clc\\n\"\n";
    uint32_t base_address = 0x780;
    for(int j = 0;j<branches - 1;j++)
    {
        if(j == 0)
        {
            outfile << "\"mov $10, \%eax\\n\"\n";
            outfile << "\"cmp $15, \%eax\\n\"\n";
            outfile << "\"jle l" << std::hex << (base_address + (j * distance)) << "\\n\"\n";
        }
        else
            outfile << "jle l" << std::hex << (base_address + (j * distance)) << "\\n\"\n";
        outfile << "\"clc\\n\"\n";
        outfile << "\"clc\\n\"\n";
        outfile << "\"clc\\n\"\n";

        for(int k = 1; k <= num_mov; k++)
        {
            outfile << "\"mov $10, \%eax\\n\"\n";
        }
        for(int k = 1; k <= num_cmp; k++)
        {
            outfile << "\"cmp $15, \%eax\\n\"\n";
        }
        for(int k = 1; k <= num_clc; k++)
        {
            outfile << "\"clc\\n\"\n";
        }
        
        outfile << "\"l" << std::hex << (base_address + (j * distance)) << ": ";
    }
    
    outfile << "clc\"\n";
    outfile << ");\n";
    outfile << "}\n";
    outfile << "}\n";
    cout << "Writing the contents into the file " << file_name << "\n";
    outfile.close();
    cout << "Closed the file " << file_name << "\n";
    return 0;
}
