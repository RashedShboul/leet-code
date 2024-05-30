#include <iostream>
#include <map>
using namespace std;
class Node {
    public: 
        bool endOfWord;
        Node *children[26]; // Array of pointers to Node
        Node()
        {
            endOfWord = false; 
            for (int i = 0; i < 26; ++i)
                children[i] = nullptr;
        }
}; 
class Trie
{
private:
Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *cur = root;
        int idx;
        for (int i = 0; i < word.size(); ++i)
        {
            idx = word[i] - 'a';
            if (cur->children[idx] == nullptr)
            {
                cur->children[idx] = new Node();
            }
            cur = cur->children[idx];
        }
        cur->endOfWord = true;
    }

    bool search(string word)
    {
        Node *cur = root;
        int idx;
        for (int i = 0; i < word.size(); ++i)
        {
            idx = word[i] - 'a';
            if (cur->children[idx] == nullptr)
                return false;
            cur = cur->children[idx];
        }
        return cur->endOfWord;
    }

    bool startsWith(string prefix)
    {
        Node *cur = root;
        int idx;
        for (int i = 0; i < prefix.size(); ++i)
        {
            idx = prefix[i] - 'a';
            if (cur->children[idx] == nullptr)
                return false;
            cur = cur->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */