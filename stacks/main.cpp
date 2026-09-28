#include <iostream>
#include "ArrayStack.h"
//#include "LinkedStack.h"

using std::cout;

void test_array_stack(int capacity)
{
    cout << "\n\n--Testing ArrayStack with capacity " << capacity << "--\n\n";
    ArrayStack<int> s{capacity};
    for(int i{0}; i < capacity; ++i)
    {
        cout << "Pushing: " << i << "\n";
        s.push(i);
        cout << "Peeking into stack: " << s.peek() << "\n";
    }

    while(!s.is_empty())
    {
        cout << "Popping from stack: " << s.pop() << "\n";
    }
}

/**
 * void test_linked_stack(int max)
{
    cout << "\n\n--Testing LinkedStack with " << max << " values--\n\n";
    LinkedStack<int> s{};
    for(int i{0}; i < max; ++i)
    {
        cout << "Pushing: " << i << "\n";
        s.push(i);
        cout << "Peeking into stack: " << s.peek() << "\n";
    }

    while(!s.is_empty())
    {
        cout << "Popping from stack: " << s.pop() << "\n";
    }
} **/

int main()
{
    test_array_stack(10);
    //test_linked_stack(20);
    return 0;
}