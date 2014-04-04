#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include<string.h>
#include<iostream>
#include<cstdlib>
using namespace std;
template<class Obj>
class DoubleLinkedList
{
public:

    DoubleLinkedList();
    DoubleLinkedList(const DoubleLinkedList<Obj> &rhs);
    const DoubleLinkedList<Obj>& operator = (const DoubleLinkedList<Obj> & rhs);



    void addNode(Obj obj);
    void removeNode(Obj obj);
    void print();
    void printReverse();
    void wipe();

    virtual ~DoubleLinkedList();





protected:
private:

    //Sets the Node struct to be called a little easier
    //by typefefining it to *nPtr.
    typedef struct Node
    {
        Node * next;
        Node * prev;
        Obj obj;
    }* nPtr;

    nPtr head;
    nPtr temp;
    nPtr curr;
    nPtr tail;

    int size;


};

#endif // DOUBLELINKEDLIST_H
