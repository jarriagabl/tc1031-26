#ifndef HTABLE_H
#define HTABLE_H

#include <vector>
#include <tuple>
#include <iostream>
#include <functional>
#include "DuplicateKeyException.h"
#include "KeyNotFoundException.h"

template <typename K, typename V>
class HTable
{
private:
    // vector of tuples<occupied?, key, value>
    // use std::get<type>(table[i]) to retrieve tuple elements
    std::vector<std::tuple<bool, K, V>> table;

    // hash for key type
    std::hash<K> h;

    // Returns index for key based on hash
    int position(K key)
    {
        return h(key) % table.size();
    }

public:
    HTable(int size): table(size)
    {
    }

    void print()
    {
        std::cout << "{\n";
        for(auto p : table)
        {
            if(std::get<bool>(p))
            {
                std::cout << "\t" << std::get<K>(p) << ": " << std::get<V>(p) << "\n";
            }
        }
        std::cout << "}\n";
    }

    // Adds <key, value> to map at position determined
    // by key, if occupied, use linear probing to 
    // determine next position
    // Throws DuplicateKeyException if key already in map
    void add(K key, V value)
    {
        int i{position(key)};
        while(std::get<bool>(table[i]))
        {
            if(std::get<K>(table[i]) == key)
            {
                throw DuplicateKeyException{};
            }
            i = (i + 1) % table.size();
            if (i == position(key))
            {
                return;
            }
        }
        table[i] = std::tuple<bool, K, V>{true, key, value};
    }

    // Retrieves value associated with key
    // Throws KeyNotFoundException if key not in map
    V get(K key)
    {
        int i{position(key)};
        while(std::get<bool>(table[i]))
        {
            if(std::get<K>(table[i]) == key)
            {
                return std::get<V>(table[i]);
            }
            i = (i + 1) % table.size();
            if (i == position(key))
            {
                break;
            }
        }
        throw KeyNotFoundException{};
    }
};

#endif