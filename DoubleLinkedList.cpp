#include "DoubleLinkedList.h"
template<class Obj>
DoubleLinkedList<Obj>::DoubleLinkedList()
{
    head = NULL;
    curr = NULL;
    temp = NULL;
    tail = NULL;
}




template<class Obj>
DoubleLinkedList<Obj>::DoubleLinkedList(const DoubleLinkedList<Obj> &rhs)
{
    size = rhs.size;
    head = NULL;
    curr = NULL;
    temp = NULL;
    tail = NULL;

    nPtr n = new Node;

//iterate through the rhs
//get the obj for each node
//make a new node in this
//add the node

    n = rhs.head;
    while(n != NULL)
    {
        addNode(n->obj);
        n = n->next;
    }
}



template <class Obj>
const DoubleLinkedList <Obj>&
DoubleLinkedList<Obj>::  operator = (const DoubleLinkedList<Obj>& rhs)
{

    size = rhs.size;
    head = NULL;
    curr = NULL;
    temp = NULL;
    tail = NULL;


   wipe();

    if (this == &rhs)
    {
        return *this;
    }


    size = rhs.size;
    nPtr n = new Node;
    n = rhs.head;

    while(n != NULL)
    {
        cout<<"overloaded = "<< n->obj<<endl;

        addNode(n->obj);
        n = n->next;
    }
    return *this;

}

template<class Obj>
void
DoubleLinkedList<Obj>::addNode(Obj obj)
{
    nPtr n = new Node;
    tail = n;
    n->next = NULL;
    n->obj = obj;

    if (head != NULL)
    {
        curr= head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = n;
        n->prev = curr;
    }

    else
    {
        head = n;
        n->prev = NULL;
    }
    size++;
}



template<class Obj>
void
DoubleLinkedList<Obj>::removeNode(Obj obj)
{
    nPtr d = NULL;
    temp = head;
    curr = head;

    while(curr != NULL && obj != curr->obj)
    {
        temp = curr;
        curr = curr->next;
    }
    if (curr == NULL )
    {
        std::cout<<"deleted obj was unfound\n";
    }
    else
    {
        std::cout<<"found \n";
        d = curr;
        curr = curr->next;
        temp->next = curr;
        if (d == head)
        {
            head = head->next;
            temp = NULL;
        }


        if (curr == NULL)
        {
            tail = d->prev;
        }
        else
        {
            curr->prev = temp;
        }
        std::cout<<"deleted "<< d->obj<<" \n";

        delete d;
        size--;

    }

}

template<class Obj>
void
DoubleLinkedList<Obj>::print()
{
//base:
    curr = head;
    while (curr!=NULL)
    {
        std:: cout<< curr->obj<<",  ";
        curr = curr->next;
    }
}

template<class Obj>
void
DoubleLinkedList<Obj>::printReverse()
{

    curr = tail;
    while (curr!=NULL)
    {
        std:: cout<< curr->obj<<",  ";
        curr = curr->prev;
    }
}


template<class Obj>
void
DoubleLinkedList<Obj>::wipe()
{
    curr = head;
    while(curr!= NULL)
    {
        temp = curr;
        curr = curr->next;
        delete temp;
    }
    delete curr;
}



template<class Obj>
DoubleLinkedList<Obj>::~DoubleLinkedList()
{
  wipe();
}
