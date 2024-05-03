// Additionally constructed Doubly Linked List header file sets up the LinkedDeque (Double Ended Queue)

#include <iostream>
#include <string>

typedef std::string Elem; // list type string Elem
class Node
{                             // doubly linked list node class
    private:                      // private type definitions
        Elem elem;                // node element value
        Node *prev;               // previous node
        Node *next;               // next node
        friend class DLinkedList; // allows access DLinkedList class
};

class DLinkedList
{                                 // doubly linked list class
    public:                           // public defined methods
        DLinkedList();                // constructor method
        ~DLinkedList();               // destructor method
        bool empty() const;           // boolean method detects for empty list
        const Elem &front() const;    // get front element of list
        const Elem &back() const;     // get back element of list
        void addFront(const Elem &e); // add front of list
        void addBack(const Elem &e);  // add back of list
        void removeFront();           // remove from the front
        void removeBack();            // remove from the back

    private:           // private type definitions
        Node *header;  // lists node sentinels...
        Node *trailer; //

    protected:                            // localized utility methods
        void add(Node *v, const Elem &e); // inserts a new node 'e' before Node 'v'
        void remove(Node *v);             // removes the node 'v'
};