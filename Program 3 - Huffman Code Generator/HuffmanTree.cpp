/************************************************************************************
 * " Programming Project #3: Pair Programming (Huffman Tree Code Generator) "
 *  by Gabriel Adelemoni & Dylan Skroskznik
 *
 *   The HuffmanTree source file constructs class methods applying map structure
 *      for fitting characters to their frequency as a Huffman Table, followed by
 *      implementing the string into a vector designed Heap Priority Queue.
 *   The Heap Queue contains the string to help compress the string characters by
 *      character into encoding every leaf node to appending their own prefix string
 *      of code. We than gather this tree structure to serialize the traveral
 *      from node to node, and create a string algorithm decoded apart from the tree
 *   Finally, decompressing the serialized string leads to decoding the input code,
 *      decompressing rebuilds a stacks-based tree from the serialized string
 *      instructions, and traversing across the stack while noting each nodes
 *      prefix bits until the ending leaf node, will match the desired character
 *      to encode the matching compressed input string.
 ************************************************************************************/

#include "HuffmanTree.hpp"
HuffmanTree::HuffmanTree() {} // end constructor

std::string HuffmanTree::compress(const std::string inputStr) // compress input string function
{
    std::map<char, size_t> charFreq;
    for (auto &x : inputStr)
    {
        charFreq[x]++;
    }
    for (auto pair : charFreq)
    {
        HuffmanNode *n = new HuffmanNode(pair.first, pair.second);
        hq.insert(n);
    }
    while (hq.size() > 1)
    {
        HuffmanNode *tempNode1 = hq.min();
        hq.removeMin();
        HuffmanNode *tempNode2 = hq.min();
        hq.removeMin();
        HuffmanNode *tempParent = new HuffmanNode('\0', tempNode1->getFrequency() + tempNode2->getFrequency(), nullptr, tempNode1, tempNode2);
        hq.insert(tempParent);
    }

    encode(hq.min(), "");
    for (auto &x : inputStr)
    {
        outputStr.append(charCodes.at(x));
    }

    serialized(hq.min());
    deallocate_heap();
    return outputStr;

} // end compress

void HuffmanTree::encode(HuffmanNode *root, std::string tempString)
{
    if (root != nullptr)
    {
        if (root->getFrequency() != '0')
        {
            charCodes.insert(std::pair<char, std::string>(root->getCharacter(), tempString));
        }
        encode(root->left, tempString + "0");
        encode(root->right, tempString + "1");
    }
    else
        return;
} // end encode

void HuffmanTree::serialized(HuffmanNode *root) // get prefix code from given leaf node
{
    if (root == nullptr)
        return;
    serialized(root->left);
    serialized(root->right);
    if (root->isLeaf())
    {
        serial = serial + "L" + root->getCharacter();
    }
    if (root->isBranch())
    {
        serial += "B";
    }
} // end serialized

std::string HuffmanTree::serializeTree() const
{
    return serial;
} // end serializeTree

std::string HuffmanTree::decompress(const std::string inputCode, const std::string serializedTree)
{
    decompress_tree(serializedTree); // calls method to decompres serialized tree into stack
    return decoding_str(inputCode);  // returns decoded 0/1 branch tree
} // end decompress

void HuffmanTree::decompress_tree(std::string serializedTree) // reconstruct(deserialize) the serializedTree string
{
    size_t x = 1; // undefined standard int placement variable
    while (x < serializedTree.length())
    {                                                                                                           // while loop indexes as long 'x' is LESS than the length of serializedTree string
        cur = serializedTree.at(x);                                                                             // reassign 'cur' to each character 'B' or 'L' at index 'x'
        if ((serializedTree.at(x) == 'B' && serializedTree.at(x - 1) == 'L' && serializedTree.at(x - 2) == 'L') // if-statement to clarify postition of character node from leaf or branch indicators
            || (serializedTree.at(x) == 'B' && serializedTree.at(x - 1) != 'L'))
        {
            HuffmanNode *right = treeStack.top(); // builds stack-based tree with leaves, branches, and the parent nodes
            treeStack.pop();                      //...
            HuffmanNode *left = treeStack.top();
            treeStack.pop();
            HuffmanNode *parent = new HuffmanNode('\0', 1, nullptr, left, right);
            treeStack.push(parent); // pushes new node to attach subtree above which keeps binary tree consistency
        }
        else if (serializedTree.at(x - 1) == 'L')
        {
            if (!(serializedTree.at(x) == 'B' && serializedTree.at(x - 1) == 'L' && serializedTree.at(x - 2) == 'L'))
            {
                treeStack.push(new HuffmanNode(serializedTree.at(x), 1));
            }
            else
            {
            }
        }
        ++x;
    }
}

std::string HuffmanTree::decoding_str(std::string inputCode)
{
    HuffmanNode *node_leaf = treeStack.top();
    HuffmanNode *cur_node_leaf = node_leaf;
    for (char x : inputCode)
    {
        if (x == '1')
        {
            cur_node_leaf = cur_node_leaf->right;
        }
        if (x == '0')
        {
            cur_node_leaf = cur_node_leaf->left;
        }
        if (cur_node_leaf->isLeaf())
        {
            outputStr += cur_node_leaf->getCharacter();
            cur_node_leaf = node_leaf;
        }
    }
    return outputStr;
} // end decoding_str

HuffmanTree::~HuffmanTree() // HuffmanTree deconstructor method
{
    if (!hq.empty())
    {                               // if heap queue is not empty
        deconstruct_tree(hq.min()); //...call decontruct tree to recursively delete nodes all the way until the root,
        delete hq.min();            //...after root is deleted, we delete the heap queue strucuture
    }
} // end deconstructor

void HuffmanTree::deconstruct_tree(HuffmanNode *root) // Huffman tree deconstructor method
{
    if (root->left != nullptr)
    {
        deconstruct_tree(root->left);
    } // while left node is not a nullptr, recursively proceed to next node
    else if (root->left != nullptr)
    {
        deconstruct_tree(root->right);
    } // while right node is not a nullptr, recursively proceed to next node
    if (root)
    {
        delete root;
    } // when root is located, delete root
} // end deconstruct_tree

void HuffmanTree::deallocate_heap() // memory deallocating of heap queue method
{
    while (!hq.empty())
    {                   // while heap queue is not empty,
        hq.removeMin(); //...remove each min nodes value one by one until its memory is empty
    }
} // end deallocate_heap