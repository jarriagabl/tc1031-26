#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue>
#include <iostream>

using std::vector;
using std::queue;
using std::cout;

template <typename T>
class Graph
{
private:
    vector<T> nodes; // Vector of nodes' contents
    vector<vector<bool>> adjacency; // Adjacency matrix
    int num_nodes; // Current number of nodes
    int capacity; // Current max number of nodes

    void resize_graph()
    {
        nodes.resize(capacity);
        adjacency.resize(capacity);
        for(int i{0}; i < capacity; ++i)
        {
            adjacency[i].resize(capacity);
        }
    }

    // Returns node's index or -1 if not found
    int get_node_index(T node_val)
    {
        for(int i{0}; i < num_nodes; ++i)
        {
            if(nodes[i] == node_val)
            {
                return i;
            }
        }
        return -1;
    }

public:
    Graph(int capacity): capacity{capacity}, num_nodes{0}, nodes{}, adjacency{}
    {
        resize_graph();
    }

    bool add_node(T value)
    {
        // Check if node already in graph
        if(get_node_index(value) != -1)
        {
            return false;
        }
        // Check if capacity has not been exceeded
        if(num_nodes >= capacity)
        {
            capacity = capacity * 2;
            resize_graph();
        }
        nodes[num_nodes++] = value;
        return true;
    }

    void add_edge(T src, T dst)
    {
        // Get both nodes (source and dest) index
        int s{get_node_index(src)};
        int d{get_node_index(dst)};
        // If source node not in graph, add it
        if(s == -1)
        {
            add_node(src);
            s = num_nodes - 1;
        }
        // If dest node not in graph, add it
        if(d == -1)
        {
            add_node(dst);
            d = num_nodes - 1;
        }
        adjacency[s][d] = true;
        adjacency[d][s] = true; // Delete line for not directed graph
    }

    vector<T> neighbors(T value)
    {
        int i{get_node_index(value)};
        vector<T> ns{};
        if(i != -1)
        {
            for(int j{0}; j < num_nodes; ++j)
            {
                if(adjacency[i][j])
                {
                    ns.push_back(nodes[j]);
                }
            }
        }
        return ns;
    }

    template <typename F>
    void bfs(T value, F& fun)
    {
        vector<bool> visited(num_nodes);
        queue<T> q{};
        int idx{get_node_index(value)};
        if(idx == -1) return;
        fun(value);
        visited[idx] = true;
        q.push(value);
        while(!q.empty ())
        {
            for(auto n : neighbors(q.front()))
            {
                int jdx{get_node_index(n)};
                if(!visited[jdx])
                {
                    fun(n);
                    q.push(n);
                    visited[jdx] = true;
                }
            }
            q.pop();
        }
    }

    void print()
    {
        cout << "\t";
        for(int i{0}; i < num_nodes; ++i)
        {
            cout << nodes[i] << "\t";
        }
        cout << "\n";
        for(int i{0}; i < num_nodes; ++i)
        {
            cout << nodes[i] << "\t";
            for(int j{0}; j < num_nodes; ++j)
            {
                cout << adjacency[i][j] << "\t";
            }
            cout << "\n";
        }
    }
};
#endif