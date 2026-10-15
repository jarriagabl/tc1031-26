#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include "Node.h"

template <typename T>
class LinkedQueue
{
private:
    Node<T> *front;
    Node<T> *back;
    int num_elements;

public:
    LinkedQueue(): front{nullptr}, back{nullptr}, num_elements{0}
    {
    }

    void enqueue(T element)
    {
        Node<T> *new_node{new Node<T>{element}};
        if(is_empty())
        {
            front = new_node;
        } else
        {
            back->next = new_node;
        }
        back = new_node;
        ++num_elements;
    }

    T get_front()
    {
        return front->data;
    }

    T dequeue()
    {
        Node<T> *to_delete{front};
        T to_return{front->data};
        front = front->next;
        delete to_delete;
        --num_elements;
        if(is_empty())
        {
            back = nullptr;
        }
        return to_return;
    }

    bool is_empty()
    {
        return num_elements == 0;
    }

    ~LinkedQueue()
    {
        while(!is_empty())
        {
            dequeue();
        }
    }

};
#endif