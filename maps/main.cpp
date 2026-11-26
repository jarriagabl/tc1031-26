#include <string>
#include <iostream>
#include "HTable.h"
#include "CTable.h"

using std::string;
using std::cout;

int main()
{
    HTable<int, string> map{5};     // Comment line to test CTable
    //CTable<int, string> map{5};   // Uncomment line to test CTable
    try
    {
        cout << "Adding " << 1 << ": uno\n";
        map.add(1, "uno");

        cout << "Adding " << 2 << ": dos\n";
        map.add(2, "dos");

        cout << "Adding " << 22 << ": veintidos\n";
        map.add(22, "veintidos");

        cout << "Adding " << 101 << ": cientouno\n";
        map.add(101, "cientouno");

        cout << "Adding " << 1 << ": UNO!\n";
        map.add(1, "UNO!");
    } catch(const std::exception &e)
    {
        std::cerr << "EXCEPTION: " << e.what() << "\n";
    }

    try
    {
        cout << "\nGetting key: " << 1 << ", value: " << map.get(1);
        cout << "\nGetting key: " << 2 << ", value: " << map.get(2);
        cout << "\nGetting key: " << 22 << ", value: " << map.get(22);
        cout << "\nGetting key: " << 101 << ", value: " << map.get(101);
        cout << "\nGetting key: " << 102 << ", value: " << map.get(102);
    }
    catch(const std::exception& e)
    {
        std::cerr << "EXCEPTION: " << e.what() << '\n';
    }

    cout << "\nPrinting contents:\n";
    map.print();
}