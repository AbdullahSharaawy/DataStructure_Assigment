#include "Stack.h"

#include<iostream>
using namespace std;
int main()
{
    Stack<int> s;

    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);
  
   
    // Check size
    std::cout << "Stack size: " << s.size() << std::endl;

    // Access top element
    std::cout << "Top element: " << s.top() << std::endl;

    // Pop elements
    s.pop();
    std::cout << "Top after pop: " << s.top() << std::endl;

    // Check if empty
    if (!s.empty()) {
        std::cout << "Stack is not empty" << std::endl;
    }

	
}
