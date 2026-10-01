#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include "Node.h"

template <typename T>
class LinkedStack
{
private:
    Node<T> *top;
    int num_elements;

public:
    LinkedStack(): top{nullptr}, num_elements{0}
    {
    }

    void push(T new_element)
    {
        Node<T> *new_node{new Node<T>{new_element}};
        new_node->next = top;
        top = new_node;
        ++num_elements;
    }

    T peek()
    {
        return top->data;
    }

    T pop()
    {
        T to_return{top->data};
        Node<T> *to_delete{top};
        top = to_delete->next;
        delete to_delete;
        --num_elements;
        return to_return;
    }

    int size()
    {
        return num_elements;
    }

    bool is_empty()
    {
        return num_elements == 0;
    }

    ~LinkedStack()
    {
        while(!is_empty())
        {
            pop();
        }
    }

};

#endif
