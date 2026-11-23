#include <iostream>
#include "Graph.h"

using std::cout;

int main()
{
    Graph<char> g{5};
    auto f = [](char c){cout << c << " ";};

    g.add_edge('A', 'B');
    g.add_edge('A', 'D');
    g.add_edge('E', 'B');
    g.add_edge('D', 'C');
    g.add_edge('E', 'C');
    g.add_edge('E', 'F');
    g.add_edge('E', 'G');
    g.add_edge('D', 'G');

    for(auto n : g.neighbors('A'))
    {
        cout << n << " ";
    }
    cout << "\n";

    g.print();
    cout << "BFS from A: ";
    g.bfs('A', f);
    cout << "\n";
}