#include <iostream>
#include "ArrayQueue.h"
#include "LinkedQueue.h"

using std::cout;

void test_array_queue(int capacity)
{
    cout << "\n\n--Testing ArrayQueue with capacity " << capacity << "--\n\n";
    ArrayQueue<int> q{capacity};
    for(int i{0}; i < capacity; ++i)
    {
        cout << "Enqueuing " << i << "...\n";
        q.enqueue(i);
        cout << "Getting " << q.get_front() << " from the front.\n";
    }

    while(!q.is_empty())
    {
        cout << "Getting " << q.get_front() << " from the front.\n";
        cout << "Dequeuing " << q.dequeue() << " from the front.\n";
    }
}

void test_linked_queue(int max)
{
    cout << "\n\n--Testing LinkedQueue with " << max << " values--\n\n";
    LinkedQueue<int> q{};
    for(int i{0}; i < max; ++i)
    {
        cout << "Enqueuing " << i << "...\n";
        q.enqueue(i);
        cout << "Getting " << q.get_front() << " from the front.\n";
    }

    while(!q.is_empty())
    {
        cout << "Getting " << q.get_front() << " from the front.\n";
        cout << "Dequeuing " << q.dequeue() << " from the front.\n";
    }
}

int main()
{
    test_array_queue(5);
    //test_linked_queue(5);
    return 0;
}