#include<iostream>
#include<map>
using namespace std; 

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr; 
        unordered_map<Node*,Node*> mp; 
        Node* ptr = head; 
        Node* dummy = new Node(-1);
        Node* ptrNewList = dummy;
        //create the new list and map each newNode to the original node 
        while (ptr != nullptr) {
            ptrNewList->next = new Node(ptr->val); 
            ptrNewList = ptrNewList->next;
            mp[ptr] = ptrNewList; 
            ptr = ptr->next; 
        }  
        ptr = head; 
        ptrNewList = dummy->next;
        //adjust random pointer 
        while (ptr != nullptr) {
            if (ptr->random != nullptr)
            ptrNewList->random = mp[ptr->random]; 
            ptrNewList = ptrNewList->next; 
            ptr = ptr->next;  
        }
        return dummy->next; 

    }
};