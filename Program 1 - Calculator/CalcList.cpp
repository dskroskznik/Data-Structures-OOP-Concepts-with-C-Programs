/************************************************************************************
 * " Programming Project #1: Pair Programming (Calculator) "
 *  by Gabriel Adelemoni & Dylan Skroskznik
 *
 * Calculator List source file to implement Doubly Linked List class functions.
 * Doubly linked list class functions builds and displays the process for
 *  calculating nodes element value from an operation function and operands.
 *  The calculator functions work to operate identically to a normal calculator
 *  and keep a running total throughout each individual operation, each number
 *  of operations done, and an undo function to remove the previous arithmetic
 *  function done.
 ***********************************************************************************/
#include <iostream>
#include <string>
#include "CalcList.hpp"

CalcList::CalcList()
{                    // constructor function
    head = new Node; // create sentinels for list
    base = new Node;
    trail = new Node;

    base->element = 0; // initialize element value '0' to base pointer node
    head->next = base; // have sentinels connected to one another
    base->prev = head;
    base->next = trail;
    trail->prev = base;
} // end CalcList

CalcList::~CalcList()
{ // destructor function
    while (!empty())
        removeLastOperation(); // undo all operations until sentinels
    delete head;               // delete sentinels
    delete base;
    delete trail;
} // end ~CalcList

bool CalcList::empty() const
{                                 // boolean function if list is empty
    return (base->next == trail); // have base sentinel point to end trail node
} // end empty

double CalcList::total() const
{                                // keep element number total at final node before trail
    return trail->prev->element; // assigns element to trails previous node
} // end total

void CalcList::addToBack(const double e)
{                       // insert new node for point to end of list
    Node *u = new Node; // create new node for element 'e'
    u->element = e;
    u->next = trail;       // link 'u' node between trail
    u->prev = trail->prev; //... and node before the trail
    trail->prev = u;       // node before trail is 'u' node
    trail->prev->prev->next = trail->prev;
} // end addToBack

void CalcList::newOperation(const FUNCTIONS func, const double element)
{ // arithemtic operations provided in each node
    if (func == ADDITION)
    {                                       // Addition Function:
        addToBack(total() + element);       // adds element to total func to back node
        trail->prev->prev->Operation = "+"; // declares operation character to variable
    }

    if (func == SUBTRACTION)
    {                                       // Subtraction Function:
        addToBack(total() - element);       // subtracts element to total func to back node
        trail->prev->prev->Operation = "-"; // declares operation character to variable
    }

    if (func == MULTIPLICATION)
    {                                       // Multiplication Function:
        addToBack(total() * element);       // multiplies element to total func to back node
        trail->prev->prev->Operation = "*"; // declares operation character to variable
    }

    if (func == DIVISION)
    { // Division Function:
        if (element == 0)
        {                                                                    // checks if element value is '0'
            throw std::invalid_argument("Operations cannot divide by zero"); // throws exception argument for operation
        }
        else
        {
            addToBack(total() / element);       // divides element to total func to back node
            trail->prev->prev->Operation = "/"; // declares operation character to variable
        }
    }

    trail->prev->prev->operand = element; // element shifts to new node operand
    operationCount++;                     // increment operation count
} // end newOperation

void CalcList::removeLastOperation()
{ // undo last operation function
    if (empty())
    {                                                                                            // check for empty linked list
        throw std::runtime_error("Removal of operations from an empty CalcList is not allowed"); // throws exeption argument for funtion
    }
    else
    {
        Node *u = trail->prev->prev; // new node predecessor
        Node *temp = trail->prev;    // new node successor
        u->next = trail;             // unlink the 'temp' node
        trail->prev = u;             //..to remove the node
        delete temp;
        operationCount--; // decrements node count
    }
} // end removeLastOperation

std::string CalcList::toString(unsigned short precision) const
{                                         // string functions, outputs calculator operations list with implemented precision
    int numOfOperations = operationCount; // convert operation count to int
    Node *current = trail->prev;          // new pointer node points to current nodes element

    std::string output; // string object to return
    while (numOfOperations > 0)
    {                                                                                                // while operations done greater than '0'
        std::stringstream ta;                                                                        // defines 'ta' to string stream breaksup individual string values
        ta.precision(precision);                                                                     // give 'ta' precision value
        ta << std::fixed << numOfOperations << ": " << current->prev->element                        // outputs 'ta' formatted to a calculator display by operation
           << current->prev->Operation << current->prev->operand << "=" << current->element << "\n"; //...using node pointers to display current element/operand
        output.append(ta.str());                                                                     // appends the 'ta' fixed "string stream" into output "string" value
        numOfOperations--;                                                                           // decrement to next
        current = current->prev;                                                                     // points current value to previous node
    }
    return output; // outputs final "string" display in calculator format
} // end toString