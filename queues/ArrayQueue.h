#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

template <typename T>
class ArrayQueue
{
private:
    T *queue;
    int front;
    int back;
    int num_elements;
    int capacity;

public:
    ArrayQueue(int capacity): queue{new T[capacity]}, front{0}, back{0}, num_elements{0},
    capacity{capacity}
    {
    }

    void enqueue(T element)
    {
        queue[back] = element;
        ++num_elements;
        back = (back + 1) % capacity;
    }

    T get_front()
    {
        return queue[front];
    }

    T dequeue()
    {
        T element{queue[front]};
        --num_elements;
        front = (front + 1) % capacity;
        return element;
    }

    int size()
    {
        return num_elements;
    }

    bool is_empty()
    {
        return num_elements == 0;
    }

    ~ArrayQueue()
    {
        delete[] queue;
    }
};
#endif