#include <iostream>
#include <vector>
#include "BST.h"

using std::cout;
using std::vector;

int main()
{
    // Create bst
    BST<int> tree{};
    // Declare lambda function to print node contents
    auto f = [](int x){cout << x << " ";};
    
    // Some values to store in tree
    vector<int> v{3, 7, 1, 10, 6, 8};
    
    // Add some values
    for(int i{0}; i < v.size(); ++i)
    {
        cout << "add(" << v[i] << "): ";
        tree.add(v[i]);
        // Apply print function to tree's nodes inorder
        //tree.inorder(f);
        cout << "\n";
    }

    // Contains
    cout << std::boolalpha;
    cout << "contains(6): " << tree.contains(6) << "\n"; // True
    cout << "contains(5): " << tree.contains(5) << "\n"; // False
    
    // Remove
    cout << "remove(8): ";
    tree.remove(8);
    //tree.inorder(f);
    cout << "\n";
    
    cout << "remove(7): ";
    tree.remove(7);
    //tree.inorder(f);
    cout << "\n";

    cout << "contains(8): " << tree.contains(8) << "\n"; // True
    cout << "contains(7): " << tree.contains(7) << "\n"; // False
}