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
        //TODO Implementar dequeue
        // La estrategia es muy similar a LinkedStack (mismos pasos)
        // Considera: ¿que pasa con back cuando la fila queda vacia?
        // ¿Es necesario hacer algo adicional?
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