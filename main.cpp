#include "TrieNode.h"

using namespace std;

int main() {
    TrieNode trie;

    // insert some words into the trie
    trie.insertWord("brinewater");
    trie.insertWord("hagglefish");
    trie.insertWord("inkblot");
    trie.insertWord("eeltail");
    
    // full and partial word search
    cout << "Search for 'inkblot': " << (trie.searchWord("inkblot") ? "Found" : "Not Found") << endl;
    cout << "Search for 'hagglefish': " << (trie.searchWord("hagglefish") ? "Found" : "Not Found") << endl;
    cout << "Search for 'undertow': " << (trie.searchWord("undertow") ? "Found" : "Not Found") << endl;
    cout << "Partial search for 'blot': " << (trie.partialSearch("blot") ? "Found" : "Not Found") << endl;
    cout << "Partial search for 'rain': " << (trie.partialSearch("rain") ? "Found" : "Not Found") << endl;
    cout << "Partial search for 'lef': " << (trie.partialSearch("lef") ? "Found" : "Not Found") << endl;
    
    // print the trie
    cout << "Words in the trie: " << endl;
    trie.printWords("");

    return 0;
}