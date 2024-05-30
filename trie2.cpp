#include<iostream>
#include <string>
using namespace std; 
class Node{
public: 
    bool isWord; 
    Node* next[26]; 
    Node() {
        isWord = false; 
        for (int i=0; i<26; ++i) {
            next[i] = nullptr; 
        }
    }
}; 

class WordDictionary {
private:
    Node* root; 
    bool searchHelper(Node* node, string& word, int idx) {
        if (idx == word.size())
            return node->isWord;
        char c = word[idx]; 
        if (c == '.') {
            for (int i=0; i<26; ++i) {
                if (node->next[i] != nullptr && searchHelper(node->next[i], word, idx + 1))
                    return true; 
            }
            return false; 
        }
        else {
            int x = c - 'a'; 
            if(node->next[x] == nullptr) return false; 
            return searchHelper(node->next[x], word, idx + 1); 
        }
    }
public:
    WordDictionary() {
        root = new Node(); 
    }
    
    void addWord(string word) {
        int idx; 
        Node* ptr = root; 
        for (char c : word) {
            idx = c - 'a'; 
            if (ptr->next[idx] == nullptr) 
                ptr->next[idx] = new Node(); 
            ptr = ptr->next[idx]; 
        }
        ptr->isWord = true; 
    }
    
    bool search(string word) {
        return searchHelper(root, word, 0); 
    }
};

