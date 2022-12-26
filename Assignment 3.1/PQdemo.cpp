#include <iostream>
#include "PQ.h"
//#include "ReganPq.h"

using namespace std;

int main()
{
    PQ <int> p1;
    
    // insert ID, priority
    // Test program to test mainly for insert and print functions. (Also tests for size and makeEmpty)
    // Print should print Index Priority of element and element value in that order
    // Also testing size function 
    cout << "-----------Start of First Test-------------" << endl;
    p1.insert(1,1);
    p1.insert(2,2);
    p1.insert(3,3);
    p1.insert(5,5);
    p1.insert(6,6);
    p1.insert(7,7);
    cout << "Size is " << p1.size() << endl;

    p1.print();
    p1.makeEmpty();
    cout << "Size is " << p1.size() << endl;


    //testing my find min and delete min functions
    PQ <int> p2;

    cout << "---------Start of Second Test---------------" << endl;
    p2.insert(21,1);
    p2.insert(17,2);
    p2.insert(18,3);
    p2.insert(12,5);
    cout << "Min value is: " << p2.findMin() <<endl;
    p2.print();

    cout << "Deleting min element: " << p2.deleteMin() <<endl;
    cout << "New min value is: " << p2.findMin() << endl;
    p2.print();

    p2.makeEmpty();


    // testing my insert with random values and priorities to test for percolate_down percolate_up functions
    // also testing delete min and find min again.
    PQ <int> p3;

    cout << "---------Start of Third Test---------------" << endl;
    p3.insert(17,3);
    p3.insert(21,1);
    p3.insert(81,2);
    p3.insert(18,5);
    p3.insert(12,6);
    p3.insert(99,10);
    p3.insert(97,8);
    p3.print();
    cout << "Size is " << p3.size() << endl;

    cout << "Deleting min element: " << p3.deleteMin() <<endl;
    cout << "Deleting min element: " << p3.deleteMin() <<endl;
    cout << "Min value is: " << p3.findMin() << endl;
    cout << "Size is " << p3.size() << endl;

    p3.print();

    p3.makeEmpty();


    // testing my size, find min + delete, update priority function
    cout << "---------Start of Fourth Test---------------" << endl;
    PQ <int> p4;
    p4.insert(25,10);
    p4.insert(21,1);
    p4.insert(99,18);
    p4.insert(81,12);
    p4.insert(18,5);
    p4.insert(12,6);

    cout << "Nin value is: " << p4.findMin() << endl;
    cout << "Size is " << p4.size() << endl;
    cout << "Deleting min element: " << p4.deleteMin() <<endl;
    cout << "Nin value is: " << p4.findMin() << endl;
    cout << "Size is " << p4.size() << endl;

    //p4.updatePriority(100,2);

    p4.print();

}