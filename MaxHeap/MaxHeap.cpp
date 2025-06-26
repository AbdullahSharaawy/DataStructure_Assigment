// MinHeap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MaxHeap.h"
using namespace std;
int main()
{
    cout << "Hello World!\n";
    HeapNode* node1 = new HeapNode("Ali", 10, 5);
    HeapNode* node2 = new HeapNode("Adel", 4, 5);
    HeapNode* node3 = new HeapNode("Adham", 3, 6);
    HeapNode* node5 = new HeapNode("Menna", 5, 4);
    HeapNode* node4 = new HeapNode("Mohammed", 4, 9);
    HeapNode* node9 = new HeapNode("zaky", 9, 8);
    HeapNode* node0 = new HeapNode("sosan", 0, 1);
    HeapNode* node6 = new HeapNode("sharaawy", 6, 2);
    MaxHeap* maxHeap= new MaxHeap();
    maxHeap->insert(node1);
    maxHeap->insert(node2);
    maxHeap->insert(node3);
    maxHeap->insert(node5);
    maxHeap->insert(node4);
    maxHeap->insert(node9);
    maxHeap->insert(node0);
    maxHeap->insert(node6);
    //maxHeap->print();
    cout << maxHeap->extractMax()->getSeverity()<<endl;
    cout << maxHeap->extractMax()->getSeverity()<<endl;
    cout << maxHeap->extractMax()->getSeverity()<<endl;
    cout << maxHeap->extractMax()->getSeverity()<<endl;
    cout << maxHeap->extractMax()->getSeverity()<<endl;
    cout << maxHeap->extractMax()->getSeverity()<<endl;
    cout << maxHeap->extractMax()->getSeverity()<<endl;
    cout << maxHeap->extractMax()->getSeverity()<<endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
