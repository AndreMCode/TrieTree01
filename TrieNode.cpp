#include "TrieNode.h"

using namespace std;

// constructor to initialize a TrieNode
TrieNode::TrieNode() {
    isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        children[i] = nullptr;
    }
}

// insert a word into the trie
void TrieNode::insertWord(const string& word) {
    TrieNode* curNode = this;

    for (char ch : word) {
        int index = ch - 'a';

        if (curNode->children[index] == nullptr) {
            curNode->children[index] = new TrieNode();
        }
        curNode = curNode->children[index];
    }
    curNode->isEndOfWord = true;
}

// for full word searches
bool TrieNode::searchWord(const string& word) {
    TrieNode* curNode = this;

    for (char ch : word) {
        int index = ch - 'a';

        if (curNode->children[index] == nullptr) {
            return false;
        }
        curNode = curNode->children[index];
    }
    return curNode->isEndOfWord;
}

// helper function to check if a substring exists in the trie from a given node
bool substrSearch(TrieNode* node, const string& subStr, int pos, string currentWord) {
    if (pos >= subStr.length()) {
        return true; // full substring found
    }

    if (!node) {
        return false; // null found
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i] != nullptr) {
            char ch = 'a' + i;
            string newWord = currentWord + ch;

            // if character matches, check next part of the substring
            if (subStr[pos] == ch && substrSearch(node->children[i], subStr, pos + 1, newWord)) {
                return true;
            }

            // else continue searching beginning from this node level
            if (substrSearch(node->children[i], subStr, pos, newWord)) {
                return true;
            }
        }
    }
    return false;
}

// for partial word searches
bool TrieNode::partialSearch(const string& substring) {
    return substrSearch(this, substring, 0, "");
}


// print all word in the trie
void TrieNode::printWords(string buildWord) {
    if (isEndOfWord) {
        cout << buildWord << endl;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (children[i] != nullptr) {
            char ch = 'a' + i;
            children[i]->printWords(buildWord + ch);
        }
    }
}