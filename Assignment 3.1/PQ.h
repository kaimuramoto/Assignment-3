#ifndef PQ_H
#define PQ_H

#include "AVLTree.h"
#include "dsexceptions.h"
#include <algorithm>
#include <iostream> 
#include <vector>

using namespace std;

template <typename ID>
class PQ;

// PQ class
//
// Template parameter: ID
// Constructors:
// PQ --> constructs a new empty queue
// PQ( tasks, priorities ) --> constructs a new queue with a given set of task IDs and priorities 
// ******************PUBLIC OPERATIONS*********************
// void insert( x, p )       --> Insert task ID x with priority p 
// ID findMin( )  --> Return a task ID with smallest priority, without removing it 
// ID deleteMin( )   --> Remove and return a task ID with smallest priority 
// void updatePriority( x, p )   --> Changes priority of ID x to p (if x not in PQ, inserts x);
// bool isEmpty( )   --> Return true if empty; else false
// int size() --> return the number of task IDs in the queue 
// void makeEmpty( )  --> Remove all task IDs (and their priorities)
// ******************ERRORS********************************
// Throws UnderflowException as warranted


// ID is the type of task IDs to be used; the type must be ID (i.e., have < defined), so IDs can be AVL Tree keys.
template <typename ID>
class PQ
{
  public:

    // Constructor
    // Initializes a new empty PQ
    PQ()
    {
      currsize = 0; // current size is = 0 since we are creating an empty PQ
      min_heap.resize(1); // we want to resize our heap since usually arrays start at 0 but we want to start at 1
    }


    // Constructor
    // Initializes a new PQ with a given set of tasks IDs and priorities  
    // priority[i] is the priority for ID task[i] 
    PQ(const std::vector<ID> & tasks, const std::vector<int> & priorities)
    {
        currsize = 0;
        min_heap.resize(1);

        for(int i = 0; i < tasks.size(); i++)
        {
            insert(tasks[i], priorities[i]);
        }
    }


    // Insert ID x with priority p.
    void insert(const ID & x, int p)
    {
        if (currsize == min_heap.size()-1) 
            min_heap.resize(min_heap.size()*2);
        
        Node <ID> * ptr = new Node <ID> (x, nullptr, nullptr);
        AvlTree.insert(ptr);
        int index_0 = ++currsize;

        percolate_up( index_0, ptr, p );
    }



    // Returns an ID with minimum priority without removing it
    // Throws exception if queue is empty
    const ID & findMin() const
    {
        if(isEmpty())
        {
            throw UnderflowException{}; 
        }
        return min_heap[1].second -> element;
    }



    // Emptiness check 
    bool isEmpty() const
    {
        return currsize == 0;
    }



    // Return the number of task IDs in the queue
    int size() const
    {
        return currsize;
    } 



    // Delete all IDs from the PQ
    void makeEmpty()
    {
      currsize = 0;
    }



    // Deletes and Returns a task ID with minimum priority
    //    Throws exception if queue is empty
    const ID & deleteMin()
    {
        if(isEmpty())
        {
            throw UnderflowException {};
        }

        ID * a = new ID;

        a = & (min_heap[1].second -> element);
        min_heap[1] = min_heap[currsize];
        currsize--;
        min_heap[1].second->i = 1;

        percolate_down(1, min_heap[1].first);       

        return * a;
    }



    // Update the priority of ID x to p
    // Inserts x with p if s not already in the queue
    void updatePriority(const ID & x, int p)
    {
        int index = AvlTree.get_index(x);

        if (AvlTree.contains(x) == false)
        {
            insert(x,p);
        }

        else
        {
            if(min_heap[index].first > p)
            {
                min_heap[index].first = p;
                percolate_up(index, nullptr, p);
            }

            else if (min_heap[index].first < p)
            {
                min_heap[index].first = p;
                percolate_down(index, p);
            }
        }
    } 

    // Print function to print out the Index, Priotirty, and Element
    void print()
    {
      for (int i = 1; i <= currsize; i++) 
      {
        cout << "Index: " << min_heap[i].second->i << endl;
        cout << "Priority: " << min_heap[i].first << endl;
        cout << "Element: " << min_heap[i].second->element << endl;
      }
    }



  private:

    AvlTree <ID> AvlTree; // Initializes the AvlTree
    int currsize; //Size of our minheap
    vector < pair < int, Node <ID> * >> min_heap;


    // procolate down function
    void percolate_down(int index_0, int p)
    {
        int child;
        Node <ID> *tmp = (min_heap[index_0].second);

        for(; index_0 *2 <= currsize; index_0 = child)
        {
            child = index_0 *2;
            if(child != currsize && min_heap[ child + 1 ].first < min_heap[ child ].first)
                ++child;

            if(min_heap[child].first < p)
            {
                min_heap[index_0] = (min_heap[child]);
                min_heap[index_0].second -> i = index_0;
            }

            else
                break;
        }

        min_heap[index_0].second = (tmp);
        min_heap[index_0].first = p;
        min_heap[index_0].second->i = index_0;
    }


    //percolate up function
    void percolate_up(int index_0, Node<ID>* node, int p)
    {
    // first array stores the data while second stores the pointer
    min_heap[0].first = (p);

    // Comparing child to priority
    for(; p < min_heap[index_0 / 2 ].first; index_0 /= 2) 
    {
        min_heap[index_0] = (min_heap[index_0/2]); // Replace with parent because and keep swapping
        min_heap[index_0].second->i = index_0; // this updates the index
    }


    min_heap[index_0].first = p;

    if(node != nullptr)
    {
        min_heap[index_0].second = node;
    }
   
    min_heap[index_0].second->i = index_0; // Updates index

    }
};

#endif