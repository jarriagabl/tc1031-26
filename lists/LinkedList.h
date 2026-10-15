#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "Node.h"

using std::cout;

/**
 * Simple Single Linked List implementation
 **/
template <typename T>
class LinkedList
{
private:
    Node<T> *head;
    int num_elements;

    /**
    Gets reference to node at position 'index'
    'index' should be a valid position in the list
    in the range [-1, size] (-1: head, size: nullptr)
    **/
    Node<T> *get_node(int index)
    {
        Node<T> *n{head};
        for(int i{-1}; i < index; ++i)
        {
            n = n->next;
        }
        return n;
    }

public:

    /**
    Class Constructor
    Initializes an empty list
    **/
    LinkedList(): head{new Node<T>{}}, num_elements{0}
    {
    }

    /**
    Adds element at the beginning of the list
    **/
    void add_first(T element)
    {
        Node<T> *new_node{new Node<T>{element}};
        new_node->next = head->next;
        head->next = new_node;
        ++num_elements;
    }

    /**
    Adds elment at the end of the list
    **/
    void add_last(T element)
    {
        Node<T> *last{get_node(num_elements - 1)};
        Node<T> *new_node{new Node<T>{element}};
        last->next = new_node;
        ++num_elements;
    }

    /**
    Prints the elements of the list, separated by spaces
    **/
    void print()
    {
        Node<T> *i{head->next};
        while(i != nullptr)
        {
            cout << i->data << " ";
            i = i->next;
        }
    }

    /**
    Returns the current number of elements in the list
    **/
    int size()
    {
        return num_elements;
    }

    /**
    Returns element at the specified index
    'index' should be a valid position in the list
    in the range [0, list_size-1]
    **/
    T get(int index)
    {
        return get_node(index)->data;
    }

    /**
    Returns true if the list is empty,
    false otherwise
    **/
    bool is_empty()
    {
        return num_elements == 0;
    }

    /**
    Removes first element of the list and returns it
    List should not be empty
    **/
    T remove_first()
    {
        Node<T> *to_remove{head->next};
        T removed_data{to_remove->data};
        head->next = to_remove->next;
        delete to_remove;
        --num_elements;
        return removed_data;
    }

    /**
    Deletes every element of the list
    **/
    void clear()
    {
        while(num_elements > 0)
        {
            remove_first();
        }
    }

    /**
     * Destructor
     **/
    ~LinkedList()
    {
        clear();
        delete head;
    }

};
#endif