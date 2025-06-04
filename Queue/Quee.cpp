#include "Queue.h"
#include<iostream>
using namespace std;
int main()
{
    // Enqueue elements
    Queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);

    // Check size
    std::cout << "Queue size: " << q.size() << std::endl;

    // Access front and back elements
    std::cout << "Front element: " << q.front() << std::endl;
   
    // Dequeue elements
    q.pop();
    std::cout << "Front after dequeue: " << q.front() << std::endl;

    // Check if empty
    if (!q.empty()) {
        std::cout << "Queue is not empty" << std::endl;
    }

    // Dequeue remaining elements
    q.pop();
    q.pop();

    // Final empty check
    if (q.empty()) {
        std::cout << "Queue is now empty" << std::endl;
    }
}