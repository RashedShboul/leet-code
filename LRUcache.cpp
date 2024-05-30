#pragma once
#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    int val;
    int key;
    Node *next;
    Node *prev;
    Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr)
    {}
};
class LRUCache
{
private:
    int curSize;
    int maxSize;
    Node *first;
    Node *last;
    unordered_map<int, Node *> keys;

    //adds new node to the front of the list
    void addNode(int key, int value) {
        Node* newNode = new Node(key,value); 
        keys[key] = newNode; 
        if (curSize == 0) {
            first = last = newNode; 
        }
        else {
            newNode->prev = last; 
            last->next = newNode; 
            last = newNode; 
        }
        curSize++; 
    }

    // function to update the value of a key and move it to the front of doubly-linkedlist
    void update(int key, int value)
    {
        Node *ptr = keys[key];
        ptr->val = value;
        //if there is only one node or the node we updating is in the front of the list 
        // we dont need to change the pointers
        if (curSize == 1 || ptr == last)
            return;
        if (ptr == first)
        {
            first = first->next;
        }
        else
        {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
        }
        ptr->prev = last;
        last->next = ptr;
        last = ptr;
    }

public:
    LRUCache(int capacity)
    {
        first = nullptr;
        curSize = 0;
        maxSize = capacity;
    }

    int get(int key)
    {
        if (keys.count(key))
        {
            //using update to move the node to the front of the list (the value still the same) 
            update(key, keys[key]->val);
            return keys[key]->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (keys.count(key))
        {
            //if key exist just use update to move the node to front of the list
            update(key, value);
            return;
        }

        Node *newNode = new Node(key, value);
        keys[key] = newNode;
        
        if (curSize == maxSize) {
            Node* tmp = first;
            keys.erase(first->key); 
            first = first->next; 
            delete tmp; 
            curSize--; 
        }
        addNode(key,value); 
    }
};