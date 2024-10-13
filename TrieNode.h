#ifndef TRIENODE_H
#define TRIENODE_H

#include <iostream>
#include <string>

using namespace std;

const int ALPHABET_SIZE = 26; // using lower case letters only

class TrieNode {
public:
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode();

    void insertWord(const string& word);
    bool searchWord(const string& word);
    bool partialSearch(const string& buildWord);
    void printWords(string buildWord);
};

#endif