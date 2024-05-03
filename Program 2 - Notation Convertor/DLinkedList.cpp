// Additionally constructed Doubly Linked List source file sets up the LinkedDeque (Double Ended Queue)

#include <iostream>
#include <string>
#include "DLinkedList.hpp"

DLinkedList::DLinkedList()
{                           // constructor method
    header = new Node;      // initialize sentinel nodes
    trailer = new Node;     //...
    header->next = trailer; // point the nodes to each other
    trailer->prev = header; //...
} // end constructor

DLinkedList::~DLinkedList()
{ // destructor method
    while (!empty())
    {                  // if empty?...
        removeFront(); // removes all nodes except sentinels
    }
    delete header;  // removes sentinel nodes
    delete trailer; //...
} // end destructor

bool DLinkedList::empty() const
{ // boolean method detects for empty list
    return header->next == trailer;
} // end empty

const Elem &DLinkedList::front() const
{ // get front element of list
    return header->next->elem;
} // end front

const Elem &DLinkedList::back() const
{ // get back element of list
    return trailer->prev->elem;
} // end back

void DLinkedList::add(Node *v, const Elem &e)
{                                  // insert new node before 'v'
    Node *u = new Node;            // create node 'u' and
    u->elem = e;                   //...assign to element 'e'
    u->next = v;                   // link 'u' in between 'v'
    u->prev = v->prev;             // and  'u' previous to 'v' previous
    v->prev = u;                   // have the front of 'v' node...
    v->prev->prev->next = v->prev; // before 'u'
} // end add

void DLinkedList::remove(Node *v)
{                      // deletes node 'v' from DLinkedList
    Node *u = v->prev; // initialize predecessor node
    Node *w = v->next; //...successor node
    u->next = w;       // unlink the 'v' node from list
    w->prev = u;       //...
    delete v;          // delete 'v'
} // end remove

void DLinkedList::addFront(const Elem &e)
{ // add 'v' to the front of the DLinkedList
    add(header->next, e);
} // end addFront

void DLinkedList::addBack(const Elem &e)
{ // add 'v' to the back of the DLinkedList
    add(trailer, e);
} // end addBack

void DLinkedList::removeFront()
{ // removes 'v' from the front
    remove(header->next);
} // end removeFront

void DLinkedList::removeBack()
{ // removes 'v' from the back
    remove(trailer->prev);
} // end removeBack
