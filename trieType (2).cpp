//
// Created by abeer on 12/13/2022.
//
#include<iostream>
#include "trieType.h"
#include <cstdlib>
#include "string.h"
using namespace std;


trieType::trieType() {

    rootNode = new Node();

}

void trieType::Node::insert(std::string prefixs)
{
    trieType::Node *cur = this;

    for (int i = 0; i < prefixs.length(); i++)
    {
        int index = prefixs[i] - 'a';
        if (!cur->next[index])
            cur->next[index] = new trieType::Node();

        cur = cur->next[index];
    }
    cur->IsEndOfString = true;
}

bool trieType::Node::search(std::string word){

    // "index" is using to travel the indexes of "word" . . . . . .
    int index = 0;

    // temporarily pointing to "rootNode" using "addressCarrier"  . . . . . . . .
    trieType::Node* addressCarrier = this;

    // Iterating "word" by each index . . . .
    while (index < word.size()){

        // if index char is "NULL", program will return false . . . . .
        // Because any available word can not be "NULL" by its last index . . .
        if(addressCarrier->next[word[index] - 'a'] == NULL)
            return false;

        // "addressCarrier" is travelling to its next address pointer . . . . . .
        addressCarrier = addressCarrier->next[word[index] - 'a'];

        index++;
    }

    // a proper word will have true at its "IsEndOfString" . . . . .
    return addressCarrier->IsEndOfString;
}

bool trieType::Node::startsWith(std::string prefix){
    // temporarily pointing to "rootNode" using "cur"
    trieType::Node* cur = this;

    // Iterating "prefix" by each index
    for(int i=0; i < prefix.size(); i++){

        // if index char is "NULL", program will return false
        // Because any available prefix can not be "NULL" by its last index
        if(cur->next[prefix[i] - 'a'] == NULL)
            return false;

        // "cur" is travelling to its next address pointer
        cur = cur->next[prefix[i] - 'a'];
    }

    // a proper prefix will return true
    return true;
}
