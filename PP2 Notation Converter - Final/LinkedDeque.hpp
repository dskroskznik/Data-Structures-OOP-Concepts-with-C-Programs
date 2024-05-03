// Additionally constructed Linked Deque header file sets up the NotationConverter functionalities 

#include <iostream>
#include <string>
#include "DLinkedList.hpp"

class DequeException {                                      //applied Deque Exception base
public:                                                     //public class methods
    DequeException(const std::string err) : errMsg(err) {}  //create exception error message 
    std::string getError() { return errMsg; }               //...with access of error message
private:                                                        
    std::string errMsg;                                     //error message text
};

class DequeEmpty : public DequeException {                      //exception DequeEmpty function created
public:                                                                 
    DequeEmpty(const std::string err) : DequeException(err) {}  //calls error text with exception method initialized     
};

typedef std::string Elem;            //LinkedDeque type string Elem 
class LinkedDeque {                  //deque class in a doubly linked list structure
public: 
    LinkedDeque();                   //constructor method
    int size() const;                //item size in the deque
    bool empty() const;              //check for an empty deque
    const Elem& front() const;       //first element put to front
    const Elem& back() const;        //last element put to back
    void insertFront(const Elem& e); //insert a new element to front
    void insertBack(const Elem& e);  //insert a new element to back
    void removeFront();              //removes the first element in front
    void removeBack();               //removes the last element in back

private:
    DLinkedList D;                   //initialize element as type doubly linked list
    int n;                           //numbered value for elements 
};