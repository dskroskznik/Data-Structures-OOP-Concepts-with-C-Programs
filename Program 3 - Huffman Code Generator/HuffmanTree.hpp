/************************************************************************************
 * " Programming Project #3: Pair Programming (Huffman Tree Code Generator) "                                  
 *  by Gabriel Adelemoni & Dylan Skroskznik                                        
 *                                                                                  
 *   The HuffmanTree header file implements class methods that function             
 *       with heap prority queues, maps, binary tree builds, and stack structures.  
 *   The class NotationConverter inherits off the both HeapQueue header and         
 *      the base interface for Huffman code tree, HuffmanBase header.               
 *   Operating each of these class methods will provided structure for              
 *      compressing input strings, serializing into trees,                          
 *      and decompressing strings.                                                  
 *                                                                                  
 ************************************************************************************/
#ifndef HUFFMANTREE_HPP
#define HUFFMANTREE_HPP

#include <iostream> //include standard and ADT libraries
#include <map>
#include <string>
#include <vector>
#include <stack>
#include "HuffmanBase.hpp" //includes base class objects for creating Huffman tree
#include "HeapQueue.hpp"   //heap queue structure classes used for storing input string characters

class HuffmanTree : public HuffmanTreeBase
{                                                                                          // Huffman tree class object inherited by Base Huffman Tree objects of HuffmanBase
    public:                                                                                    // public access methods
        HuffmanTree();                                                                         // constructor
        ~HuffmanTree();                                                                        // deconstructor
        std::string compress(const std::string inputStr);                                      // compress method to compress an accessed string to input into a priorty queue for encoding
        std::string serializeTree() const;                                                     // method for constituting the serialization process within and appending the string from the serialize method
        std::string decompress(const std::string inputCode, const std::string serializedTree); // decompression method of decontructing the serializing process and decoding the tree to the output string
        void deconstruct_tree(HuffmanNode *root);                                              // private internal method to help decontruct the serialized tree easier

    protected:                                                  // secured methods and variables needed to sort the process of compressing and decompressing the string
        char cur = ' ';                                         // current character initalized when cycling through each character called in the serialized tree at certain node
        void deallocate_heap();                                 // deallocation of memory method to the heap queue after compressing when no use for the queue anymore
        void encode(HuffmanNode *root, std::string tempString); // method to encoding the created heap queue and assign traversed nodes from appending a '0' or '1' to string value
        void serialized(HuffmanNode *root);                     // main serializing process method, similar to encoding, appends a constant 'B' to serial string for declaring a branch node, and appends constant 'L' along with the current root node character to serial string for declaring a leaf node
        void decompress_tree(std::string serializedTree);       // first submethod for decompressing(reconstructing) the serialized tree while utilizing stack structure for placing nodes correctly
        std::string decoding_str(std::string inputCode);        // second submethod, after decompress, decodes the character prefix throughout input code starting from the root of the new stack based tree, and appends every leaf nodes character traversed to based on prefix code

    private:                                               // inaccessible variables and ADTs used across the compression and decompression
        HeapQueue<HuffmanNode *, HuffmanNode::Compare> hq; // main HeapQueue structure when fitting the input string to encode into a binary tree
        std::stack<HuffmanNode *> treeStack;               // utility tree stack structure created after deserializing a serial string to place into
        std::string serial;                                // the serial string variable to append leaf and branch indicators in assembled tree
        std::string outputStr;                             // main output string after finalizing the deompression process
        std::map<char, std::string> charCodes;             // map structure to create Huffman table organizing character text to their respective prefix codes
};

#endif // ends if no HUFFMANTREE_HPP