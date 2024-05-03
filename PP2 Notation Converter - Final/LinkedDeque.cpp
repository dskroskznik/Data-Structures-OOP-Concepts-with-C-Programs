// Additionally constructed Linked Deque source file sets up the NotationConverter functionalities 

#include <iostream>
#include <string>
#include "LinkedDeque.hpp"

LinkedDeque::LinkedDeque() : D(), n(0) {} //empty constructor created

int LinkedDeque::size() const{ //sees and returns number of elements in queue (may be insignificant)
    return n;
}//end size

bool LinkedDeque::empty() const{ //checks and returns for an empty queue (may be insignificant)
    return n == 0;
}//end empty

const Elem& LinkedDeque::front() const{ //searches and returns front queue element (may be insignificant)
    if(empty()){ throw DequeEmpty("Deque is empty"); } //when front is an empty queue node
    return D.front();
}//end front

const Elem& LinkedDeque::back() const{ //searches and returns back queue element (may be insignificant)
    if(empty()){ throw DequeEmpty("Deque is empty"); } //when back is an empty queue node  
    return D.back();
}//end back

void LinkedDeque::insertFront(const Elem& e){ //inserts new front element and iterates over
    D.addFront(e);
    n++;
}//end insertFront

void LinkedDeque::insertBack(const Elem& e){ //inserts new back element and iterates over
    D.addBack(e);
    n++;
}//end insertBack

void LinkedDeque::removeFront(){ //removes front element from queue and decrements over                            
    if(empty()){ throw DequeEmpty("Deque is empty"); } //throw exception DequeEmpty message
    D.removeFront();
    n--;
}//end removeFront

void LinkedDeque::removeBack(){ //removes back element from queue and decrements over
    if(empty()){ throw DequeEmpty("Deque is empty"); } //throw exception DequeEmpty message
    D.removeBack();
    n--;
}//end removeBack