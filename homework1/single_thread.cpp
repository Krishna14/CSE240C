#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <random>
#include <string>
#include <cstring>

using namespace std;

#define NUM_ITER 20
#define KB 1024
#define MB 1024 * 1024

void convert_to_lower(string& s)
{
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char ch) { return std::tolower(ch); });
}

//  cacheLine indicates the size of each block
struct cacheLine
{
    vector<int> elements;
    //  cacheLine() is the default constructor used here
    cacheLine() { elements.resize(16, 0); }
    //  cacheLine is a constructor used here
    cacheLine(string str)
    {
        cout << "Original string is " << str << "\n";
        convert_to_lower(str);
        cout << "Converted string looks as " << str << "\n";
        int numElements = 0;
        if(str.compare("x86") == 0 
            || str.compare("alpha") == 0
            || str.compare("amd") == 0)
            numElements = 16;    //  Assumption: Cache line is 64 bytes
        else if(str.compare("arm") == 0)
            numElements = 32;    //  Assumption: Cache line is 128 bytes
        elements.resize(numElements, 0);
    }
};

//  main() function has been implemented here
int main(int argc, char *argv[])
{
    //  Printing the "architecture type" and "debug_mode" knob values
    string arch;
    bool debug_mode = false;
    
    //  Accepting command line arguments
    if(argc < 2)
    {
        cout << "USAGE: ./single_thread.o --arch x86/ARM/AMD/Alpha \n";
        exit(0);
    }
    else
    {
        for(int i=1;i<argc;i++)
        {
            if(!strcmp(argv[i], "--arch"))
            {
                arch.append(argv[i+1]);
            }
            if(!strcmp(argv[i], "--debug_mode"))
            {
                debug_mode = atoi(argv[i+1]);
            }
        }
    }
    int cacheLineSize = 64;
    if(!strcmp(arch.c_str(), "x86") 
        || !strcmp(arch.c_str(), "Alpha")
        || !strcmp(arch.c_str(), "AMD"))
        cacheLineSize = 64; 
    else if(!strcmp(arch.c_str(), "ARM"))
        cacheLineSize = 128;
    
    int memorySize = 1 * KB;
    int numSets = memorySize / cacheLineSize;
    int elementsInEachLine = (cacheLineSize/sizeof(int));
    for(int i=0;i<NUM_ITER;i++)
    {
        int *line = (int*) malloc(sizeof(int) * elementsInEachLine);
        
        for(int j=0;j<elementsInEachLine;j++)
            line[j] = j;

        srand(time(0));
        //  Swap all the elements in a cache line
        for(int k=elementsInEachLine-1;k>0;k--)
        {
            int j = (rand() % k);
            int temp = *(line + k);
            *(line + k) = *(line + j);
            *(line + j) = temp;
        }
    
        cacheLine *cache = (cacheLine*) malloc(numSets * sizeof(cacheLine));
        
        for(int j=0;j<numSets;j++)
        {
            //  Here, we compute the values for each cache line
            cache[j] = cacheLine(arch);
            //  
            cache[j].elements[0] = line[j];
        }

        //  Replicate the value in one element to all other elements
        for(int k=0;k<numSets;k++)
        {
            for(int j=1;j<elementsInEachLine;j++)
            {
                cache[k].elements[j] = cache[k].elements[0];
            }
        }
        //  Here, we have created the cacheLine pointing to a particular line in the cache
    }
}
