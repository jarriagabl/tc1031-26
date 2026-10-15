#include <iostream>
#include <string>
#include "LinkedList.h"

using std::cout;
using std::string;

int main()
{
    LinkedList<int> iList{};
    cout << "Testing: add_first & add_last\n";
    for (int i = 0; i < 10; i++)
    {
        if(i % 2 == 0)
        {
            iList.add_first(i*10);
            cout << "\tadd_first(" << i * 10 << "): List: ";
            iList.print();
            cout << "\n";
        } else
        {
            iList.add_last(i*10);
            cout << "\tadd_last(" << i * 10 << "): List: ";
            iList.print();
            cout << "\n";
        }
    }

    cout << "\nTesting: get" << "\n";
    for(int i{0}; i < iList.size(); ++i)
    {
        cout << "\tget(" << i << "): " << iList.get(i) << "\n";
    }
    
    cout << "\nTesting: remove_first" << "\n";
    while (!iList.is_empty())
    {
        cout << "\tremove_first(): Removed " << iList.remove_first() << "; List: ";
        iList.print();
        cout << "\n";
    }
    return 0;
}