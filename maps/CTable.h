#ifndef CTABLE_H
#define CTABLE_H

#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <iostream>
#include "DuplicateKeyException.h"
#include "KeyNotFoundException.h"

using std::pair;
using std::vector;
using std::hash;
using std::cout;

template <typename K, typename V>
class CTable
{
private:
    // Vector of buckets of key, value pairs
    vector<vector<pair<K, V>>> buckets;
    int num_buckets;
    hash<K> h;

    int position(K key)
    {
        return h(key) %  num_buckets;
    }

public:
    CTable(int num_buckets): buckets(num_buckets), num_buckets{num_buckets}
    {
        for(int i{0}; i < num_buckets; ++i)
        {
            buckets.push_back(vector<pair<K, V>>{});
        }
    }

    void add(K key, V value)
    {
        int i{position(key)};
        auto find_key = [key](pair<K, V> p){return p.first == key;};
        if(std::find_if(buckets[i].begin(), buckets[i].end(), find_key) != buckets[i].end())
        {
            throw DuplicateKeyException{};
        }
        buckets[i].push_back(pair<K, V>{key, value});
    }

    V get(K key)
    {
        int i{position(key)};
        for(auto p : buckets[i])
        {
            if(p.first == key)
            {
                return p.second;
            }
        }
        throw KeyNotFoundException{};
    }

    void print()
    {
        std::cout << "{\n";
        for(auto b : buckets)
        {
            for(auto p : b)
            {
                std::cout << "\t" << std::get<K>(p) << ": " << std::get<V>(p) << "\n";
            }
        }
        std::cout << "}\n";
    }

};

#endif