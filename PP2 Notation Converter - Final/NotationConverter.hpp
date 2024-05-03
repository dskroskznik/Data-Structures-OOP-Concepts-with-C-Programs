/************************************************************************************
 * " Assignment #2: PP 2 (Notation Converter) "                                     *
 *  by Gabriel Adelemoni & Dylan Skroskznik                                         *
 *                                                                                  *
 *   The NotationConverter header file implements class methods that function       *
 *      doubly linked lists in a double ended queue acstract data type format.      *
 *   The class NotationConverter inherits off the NotationConverter interface, and  * 
 *      operates off the doubly linked list data structure with utility methods     *
 *      of a double ended queue data type, with element initialized type deque.     *    
 *                                                                                  *    
 ************************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
#include "NotationConverterInterface.hpp"
#include "LinkedDeque.hpp"

class NotationConverter : public NotationConverterInterface{ //abstract class inherited child of NotationConverterInterfaces
public:                                                      //public defined methods   
    NotationConverter();                                     //NotationConverter constructor method 
    std::string postfixToInfix(std::string inStr);           //string 'post-fix' to 'in-fix' editing method 
    std::string postfixToPrefix(std::string inStr);          //string 'post-fix' to 'pre-fix' editing method
    
    std::string infixToPostfix(std::string inStr);           //string 'in-fix' to 'post-fix' editing method
    std::string infixToPrefix(std::string inStr);            //string 'in-fix' to 'pre-fix' editing method
    
    std::string prefixToInfix(std::string inStr);            //string 'pre-fix' to 'in-fix' editing method
    std::string prefixToPostfix(std::string inStr);          //string 'pre-fix' to 'post-fix' editing method

private:                                                     //private type definitions
    LinkedDeque LD;                                          //initialize element as type linked deque

protected:                                                   //localized utility methods
    void loadDeque(std::string newStr);                      //loads string element into double ended queue for editing
};