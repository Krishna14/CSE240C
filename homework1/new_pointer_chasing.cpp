#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <random>
#include <cstddef>
#include <chrono>

using namespace std;

#define KB 1024
#define MB 1024 * 1024
#define NUM_ACCESSES 100000
#define NUM_ITER 20

//  pageSize = 4 * KB
const int pageSize = 4 * KB;
//  Intel processors use a 64 byte cache line
const int cacheLineSize = 64;

struct listNode
{
    listNode* next;
    std::byte padding[pageSize];
};

listNode* traverseList(listNode* head, int numOps)
{
    while(numOps--) head = head->next;
    return head;
}

uint64_t rdtsc()
{
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t) hi << 32 ) | lo;
}

int main()
{
    int size = 1*KB;
    srand(time(0));
    for(int l=0;l<NUM_ITER;l++)
    {
        int numNodes = size / cacheLineSize;
        vector<listNode> linkedList(numNodes);
        //  Create a linked list here
        for(int i=0;i<numNodes-1;i++)
            linkedList[i].next = &linkedList[i+1];
        //  Cyclic linked list is created here
        linkedList[linkedList.size() - 1].next = &linkedList[0];
        uint64_t startTime = rdtsc();
        //  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        listNode* head = traverseList(linkedList[0].next, numNodes);
        uint64_t difference = (rdtsc() - startTime)/numNodes;
        //  auto difference = std::chrono::duration_cast<std::chrono::nanoseconds> (std::chrono::steady_clock::now() - begin).count();
        cout << "Size = " << size << ", Time difference = " << difference << " [ns] \n";
        size *= 2;
    }
    return 0;
}
