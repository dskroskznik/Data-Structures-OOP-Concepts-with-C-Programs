/************************************************************************************
 * " Programming Project #1: Pair Programming (Calculator) "
 *  by Gabriel Adelemoni & Dylan Skroskznik
 *
 * Calculator List header file to implement Doubly Linked List classes.
 * Doubly linked list classifys an arbitrary Node object that defines privately
 *  secured previous and next node pointers, double & string variables
 *  holding number and operand held in the node respectively,
 *  friendship declared between the Doubly Linked List.
 * The CalcList (inherited class of CalcListInterface) builds the list
 *  constructor/destructor for the list, and functions to check an
 *  empty list, calculated numbers total, add next node towards back of list, and
 *  operation calculator calls(new operation, undo last operation).
 ***********************************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "CalcListInterface.hpp"

class Node
{                          // doubly linked list node
    private:                   // local type definitions
        Node *prev;            // previous node
        Node *next;            // follow-up node
        double element;        // element contained in node
        double operand;        // operation used within node
        std::string Operation; // operation character representation
        friend class CalcList; // allow CalcList access
};

class CalcList : public CalcListInterface
{                                                                  // double linked list struct (inherited)
    public:                                                            // global definitions to class
        CalcList();                                                    // constructor func
        ~CalcList();                                                   // destructor func
        bool empty() const;                                            // returns boolean value if list is empty
        double total() const;                                          // elements calculated total value
        int operationCount = 0;                                        // initialized operation count
        void addToBack(const double element);                          // added element node to back of double linked list
        void newOperation(const FUNCTIONS func, const double operand); // new operation function, calls a function and operand
        void removeLastOperation();                                    // remove previous operation used
        std::string toString(unsigned short precision) const;          // string display function prints calculations history
    private:                                                           // local variables
        Node *head;                                                    // pointer to nodes header
        Node *base;                                                    // pointer to base node with element '0'
        Node *trail;                                                   // pointer to node trailer
};