#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(): data{}, next{nullptr}
    {
    }

    Node(T data): data{data}, next{nullptr}
    {
    }

    Node(T data, Node<T> *next): data{data}, next{next}
    {
    }
};
#endif