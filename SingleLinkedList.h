#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H
template<class Obj>

class SingleLinkedList
{
  public:


    SingleLinkedList();
    virtual ~SingleLinkedList();
  protected:
  private:

  struct Node{
  Obj value;
  Node * next;

  };
};

#endif // SINGLELINKEDLIST_H
