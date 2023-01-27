//
// Created by abeer on 12/13/2022.
//

#ifndef TRIE_PROJECT001_TRIETYPE_H
#define TRIE_PROJECT001_TRIETYPE_H


#include <cstdlib>
#include "string.h"

// Declaring size of each executable "trieType::Node" node.
const int sizeOfNext = 26;

class string;

// trieType class . . . . .
class trieType {

public:

    // Inner Node class . . . .
    class Node{

    public:
        // initializing all important elements . . . .
        char data;
        Node* next[sizeOfNext];
        bool IsEndOfString;

        // "Node" constructor . . . . .
        Node(){

            // initially "Node" is empty, so "IsEndOfString" = false
            IsEndOfString = false;
            int index = 0;

            // filling all indexes "NULL"
            while (index < sizeOfNext){
                next[index] = NULL;
                index++;
            }
        }

        void insert(std::string);
        bool search(std::string);
        bool startsWith(std::string);
    };
    Node* rootNode;
    trieType();
};


#endif //TRIE_PROJECT001_TRIETYPE_H
