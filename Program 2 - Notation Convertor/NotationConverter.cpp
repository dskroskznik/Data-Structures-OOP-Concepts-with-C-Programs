/************************************************************************************
 * " Programming Project #2: Pair Programming (Notation Convertor) "
 *  by Gabriel Adelemoni & Dylan Skroskznik
 *
 *   The NotationConverter source files constructs class methods while applying
 *      doubly linked lists methods in a double ended queue operated data format.
 *   Double Ended Queues will operate as accessors through implemented elements
 *      in a string values, allowing for insertion of elements in the front end of
 *      a queue, but also the back end of a queue as well.
 *   The NotationConverter utilizes a deque methods to sort elements through
 *      specific arithmetic notation formats, with the sorting algorithm
 *      built dependent upon the written string format.
 *
 ************************************************************************************/

#include <iostream>
#include <string>
#include "NotationConverter.hpp"

NotationConverter::NotationConverter() : LD() {} // NotationConverter contructor built

void NotationConverter::loadDeque(std::string newStr)
{ // Deque build loads string in elements by character
    while (!LD.empty())
    {                     // deque is not empty?
        LD.removeFront(); // deletes front element and shifts up
    }

    std::string word = ""; // initialize word for use
    for (auto x : newStr)  // for loops through each element (character) in string stored in deque
    {
        if (x == '(' || x == ')' || x == ' ')
        {             // passes along deque elements if any
            continue; //...spaces or parenthesesare found
        }
        else if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x == '/') || (x == '*') || (x == '+') || (x == '-'))
        {                        // else...if 'x' is alphabetic letter or function operator characters then,
            word = x;            // stores element char to word
            LD.insertBack(word); //... and interates to back of LinkedDeque
        }
        else
        {                                                      // else...
            throw std::invalid_argument("invalid characters"); // throws exception if invalid argument discovered
        }
    }
} // end loadDeque

std::string NotationConverter::postfixToInfix(std::string inStr)
{                     // postfixToInfix notation conversion
    loadDeque(inStr); // call loadDeque function to load string data in
    while (LD.size() > 1)
    { // while the deque holds size > 1 element
        if (LD.front() != "/" && LD.front() != "*" && LD.front() != "+" && LD.front() != "-")
        {                                  // if any operator char is NOT in front of deque then,
            std::string temp = LD.front(); //...put front element into a temp string value
            LD.removeFront();              //...and remove element from the deque, interation continuing
            if (LD.front() != "/" && LD.front() != "*" && LD.front() != "+" && LD.front() != "-")
            {                                  //...if any operator char is NOT in front of deque again then,
                std::string a = LD.front();    // string value 'a' holds the following next front element
                LD.removeFront();              //...removes the next front element from the deque
                std::string oper = LD.front(); //...and string 'oper' holds the following front element then,
                LD.removeFront();              //...removes the front element of the deque once more

                std::string newStr = "(" + temp + " " + oper + " " + a + ")"; // concatenate string variables in appropriate notation formation
                LD.insertBack(newStr);                                        //...in desired format for this conversion and, insert 'newStr' to back of deque
            }
            else
            {                        // else...
                LD.insertBack(temp); // insert the first temp string to deque
            }
        }
        else
        {                                  // else...
            std::string temp = LD.front(); // if operator char is in front, initialize 'temp' string
            LD.removeFront();              //...and remove front element of the deque to,
            LD.insertBack(temp);           //...insert 'temp' to back of deque
        }
    }

    return LD.back();
} // end postfixToInfix

std::string NotationConverter::postfixToPrefix(std::string inStr)
{                                                // postfixToInfix notation conversion
    return infixToPrefix(postfixToInfix(inStr)); // calls appropriate converter function to fit notation
} // end postfixToPrefix

std::string NotationConverter::infixToPostfix(std::string inStr)
{                                                 // postfixToInfix notation conversion
    return prefixToPostfix(infixToPrefix(inStr)); // calls appropriate converter function to fit notation
} // end infixToPostfix

std::string NotationConverter::infixToPrefix(std::string inStr)
{                     // postfixToInfix notation conversion
    loadDeque(inStr); // call loadDeque function to load string data in
    while (LD.size() > 1)
    { // while the deque holds size > 1 element
        if (LD.front() != "/" && LD.front() != "*" && LD.front() != "+" && LD.front() != "-")
        {                                                                       // if any operator char is NOT in front of deque then,
            std::string temp = LD.front();                                      //...put front element into a temp string value
            LD.removeFront();                                                   //...and remove element from the deque, interation continuing
            if (LD.front().compare("/") == 0 || LD.front().compare("*") == 0 || // if follow front element compares similar to any operator
                LD.front().compare("+") == 0 || LD.front().compare("-") == 0)
            {                                  // then,
                std::string oper = LD.front(); // string value 'oper' operator holds the following front element
                LD.removeFront();              //...and remove front element
                std::string b = LD.front();    //...and string 'b' holds the next following front element then,
                LD.removeFront();              //...remove front element of the deque once more

                std::string newStr = oper + " " + temp + " " + b; // concatenate string variables in appropriate notation formation
                LD.insertBack(newStr);                            //...in desired format for this conversion and, insert 'newStr' to back of deque
            }
            else
            {                        // else...
                LD.insertBack(temp); // insert the first temp string to deque
            }
        }
        else
        {                                  // else...
            std::string temp = LD.front(); // if operator char is in front, initialize 'temp' string
            LD.removeFront();              //...and remove front element of the deque to,
            LD.insertBack(temp);           //...insert 'temp' to back of deque
        }
    }

    return LD.back();
} // end infixToPrefix

std::string NotationConverter::prefixToInfix(std::string inStr)
{                                                  // prefixToInfix notation conversion
    return postfixToInfix(prefixToPostfix(inStr)); // calls appropriate converter function to fit notation
} // end prefixToInfix

std::string NotationConverter::prefixToPostfix(std::string inStr)
{
    loadDeque(inStr); // call loadDeque function to load string data in
    while (LD.size() > 1)
    { // while the deque holds size > 1 element
        if (LD.front() == "/" || LD.front() == "*" || LD.front() == "+" || LD.front() == "-")
        {                                  // if any operator char IS in front of deque then,
            std::string temp = LD.front(); //...put front element into a temp string value
            LD.removeFront();              //...and remove element from the deque, interation continuing
            if (LD.front() != "/" && LD.front() != "*" && LD.front() != "+" && LD.front() != "-")
            {                               //...if any operator char is NOT in front of deque again then,
                std::string a = LD.front(); // string value 'a' holds the following front element
                LD.removeFront();           //...removes the next front element from the deque
                std::string b = LD.front(); //...and string 'b' holds the next following front element then,
                LD.removeFront();           //...removes the front element of the deque once more

                std::string newStr = a + " " + b + " " + temp; // concatenate string variables in appropriate notation formation
                LD.insertBack(newStr);                         //...in desired format for this conversion and, insert 'newStr' to back of deque
            }
            else
            {                        // else...
                LD.insertBack(temp); // insert the first temp string to deque
            }
        }
        else
        {                                  // else...
            std::string temp = LD.front(); // if operator char is in front, initialize 'temp' string
            LD.removeFront();              //...and remove front element of the deque to,
            LD.insertBack(temp);           //...insert 'temp' to back of deque
        }
    }

    return LD.back();
} // end prefixToPostfix