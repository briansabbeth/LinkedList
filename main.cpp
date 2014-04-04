#include <iostream>
#include "DoubleLinkedList.h"
#include "DoubleLinkedList.cpp""

using namespace std;

int main()
{
    DoubleLinkedList<int> d;

    for(int i = 0;i<10;++i)
    {
        d.addNode(i);
    }
    d.print();
    d.removeNode(0);
    d.print();

    d.removeNode(9);
    d.print();
    cout<<endl;
    d.printReverse();

    DoubleLinkedList<int> e(d);
    cout<<endl;
    e.print();
    e.removeNode(3);
    e.print();
    e = d;
    cout<<"printing new e"<<endl;
    e.print();

    return 0;
}
