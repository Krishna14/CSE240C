#include <iostream>
#include <algorithm>
#include <cmath>
#include <random>
#include <ctime>
#include <iostream>
#include <cstdint>
#include <cassert>
#include <cstring>
#include <unordered_map>

using namespace std;

#define KB 1024
#define MB 1024 * 1024
#define NUM_ACCESSES 100000
#define NUM_ITER 20

#define A_FATAL(a, b) { if (!(a)) { cout << b << endl; exit(0); } }

struct listNode
{
    int val = 0;
    listNode* next = nullptr;
    listNode* prev = nullptr;
    listNode(int ele) : val(ele)
    {
        next = nullptr, prev = nullptr;
    }
    listNode(int ele, listNode* _next_, listNode* _prev_)
    {
        val = ele;
        next = _next_;
        prev = _prev_;
    }
};

class linkedList
{
    private:
        listNode* head = nullptr;
        listNode* tail = nullptr;
        int size = 0;
    public:
        linkedList() {}
        linkedList(int numNodes) 
        {
            size = numNodes;
            for(int i=0;i<numNodes;i++)
            {
                if(head == nullptr && tail == nullptr)
                {
                    head = new listNode(i+1);
                    tail = head;
                }
                else
                {
                    listNode* newNode = new listNode(i+1);
                    newNode->prev = tail;
                    tail->next = newNode;
                    tail = tail->next;
                }
            }
            //  Converting it to a cyclic list
            tail->next = head;
            head->prev = tail;
        }
        listNode* getHeadPtr() { return head; }
        ~linkedList() {}

        //  remove(int)
        void remove(int idx)
        {
            int i =0;
            listNode* curr = head;
            while(i < idx)
            {
                curr = curr->next;
                i++;
            }
            curr->next->prev = curr->next;
            curr->prev->next = curr->next;
            delete curr;
        }

        //  insert(int)
        void insert(int ele)
        {
            if(head == nullptr && tail == nullptr)
            {
                head = new listNode(ele);
                tail = new listNode(ele);
            }
            else
            {
                listNode* newNode = new listNode(ele);
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        //  This function is used to swap the contents of the two given nodes
        void swap_two_nodes(int idx1, int idx2, bool debug_mode = false)
        {
            /*if(debug_mode)
                cout << "SWAP: swapping " << idx1 << ", and " << idx2 << "\n";
            */
            assert(idx1 >= 0 && idx1 < size);
            assert(idx2 >= 0 && idx2 < size);
            if(idx1 == idx2)
                return;
            if(size < 2)
            {
                A_FATAL(false, "Less than two nodes are present");
                return;
            }
            int i = 0;
            listNode* curr_1 = head;
            listNode* curr_2 = head;
            while(i < idx1)
            {
                assert(curr_1 != nullptr);
                curr_1 = curr_1->next;
                ++i;
            }
            int j = 0;
            while(j < idx2)
            {
                /* if(debug_mode)
                    cout << "SWAP: j = " << j << ", idx2 = " << idx2 << ", size = " << size << "\n";
                */
                assert(curr_2 != nullptr);
                curr_2 = curr_2->next;
                ++j;
            }
            //  
            listNode* next_1 = curr_1->next;
            listNode* prev_1 = curr_1->prev;
            //  
            listNode* prev_2 = curr_2->prev;
            listNode* next_2 = curr_2->next;

            if(debug_mode)
            {
                cout << "SWAP: Printing pre-swap values \n";
                if(next_1 != nullptr)
                {
                    cout << "next_1 val = " << next_1->val << ", ";
                }
                if(prev_1 != nullptr)
                {
                    cout << "prev_1 val = " << prev_1->val << ", ";
                }
                if(next_2 != nullptr)
                {
                    cout << "next_2 val = " << next_2->val << ", ";
                }
                if(prev_2 != nullptr)
                {
                    cout << "prev_2 val = " << prev_2->val << "\n";
                }
            }

            //  Assigning curr_2 between prev_1 and next_1
            if(prev_1 != nullptr)
            {
                prev_1->next = curr_2;
                curr_2->prev = prev_1;
            }
            else
            {
                curr_2->prev = nullptr;
            }

            if(next_1 != nullptr)
            {
                next_1->prev = curr_2;
                curr_2->next = next_1;
            }
            else
            {
                curr_2->next = nullptr;
            }

            //  Assigning curr_1 between prev_2 and next_2
            if(prev_2 != nullptr)
            {
                prev_2->next = curr_1;
                curr_1->prev = prev_2;
            }
            else
            {
                curr_1->prev = nullptr;
            }
        
            if(next_2 != nullptr)
            {
                next_2->prev = curr_1;
                curr_1->next = next_2;
            }
            else
            {
                curr_1->next = nullptr;
            }

            if(debug_mode)
            {
                cout << "SWAP: Printing post-swap values \n";
                if(curr_1->next != nullptr)
                {
                    cout << "next_1 val = " << curr_1->next->val << ", ";
                }
                if(curr_1->prev != nullptr)
                {
                    cout << "prev_1 val = " << curr_1->prev->val << ", ";
                }
                if(curr_2->next != nullptr)
                {
                    cout << "next_2 val = " << curr_2->next->val << ", ";
                }
                if(curr_2->prev != nullptr)
                {
                    cout << "prev_2 val = " << curr_2->prev->val << "\n";
                }
            }
        }

        int read_val(int idx)
        {
            assert(idx >=0 && idx < size);
            listNode* curr = head;
            for(int i=0;i<idx;i++)
            {
                curr = curr->next;
                assert(curr != nullptr);
            }
        }

        void print_nodes()
        {
            cout << "Printing the contents of the linked list \n";
            unordered_map<int, bool> visited;
            int curr_val = head->val;
            while(visited.find(curr_val) == visited.end() || 
                    (visited.find(curr_val) != visited.end() && visited[curr_val] == false))
            {
                cout << head->val << "\n";
                visited[head->val] = true;
                head = head->next;
                curr_val = head->val;
            }
        }
};

//  Read time stamp counter
uint64_t rdtsc()
{
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t) hi << 32 ) | lo;
}

int main(int argc, char* argv[])
{
    bool debug_mode = false;
    if(argc < 2)
    {
        cout << "USAGE: ./pointer_chasing.o --debug_mode 1/0 \n";
        exit(0);
    }
    else
    {
        for(int i=1;i<argc;i++)
        {
            if(!strcmp(argv[i], "-debug_mode"))
            {
                debug_mode = atoi(argv[i+1]);
            }
        }
    }
    //  
    srand((unsigned) time(0));
    int size = 1 * KB;
    for(int i=0;i<NUM_ITER;i++)
    {
        linkedList list = linkedList(size);
        /*
            if(debug_mode)
                list.print_nodes();
        */
        listNode* head = list.getHeadPtr();
        if(debug_mode)
            list.print_nodes();
       
        int j = 0;
        //  Swap these values to create a randomly linked list
        /*  for(int i=1;i<=size-1;i++)
        {
            int j = (rand() % (size - i));
                if(debug_mode)
                    cout << "SWAP: Values of i, j and size are " << i << ", " << j << ", " << size << "\n";
            list.swap_two_nodes(i, j, debug_mode);
        }
        */
        
        //  Start measuring the time
        uint64_t startTime = rdtsc();
        for(int i=0;i<NUM_ACCESSES;i++)
        {
            int accessIndex = rand() % size;
            //  read_val() is used to produce the value at a certain index "accessIndex"
            uint64_t value = list.read_val(accessIndex);
        }
        uint64_t endTime = rdtsc();
        cout << "Size: " << size << ", Time difference: " << float((endTime - startTime)/ (NUM_ACCESSES * size)) << "\n";
        size *= 2;
    }
    return 0;
}
