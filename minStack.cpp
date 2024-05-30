#include<iostream>
using namespace std; 

class MinStack {
private: 
    struct Node
    {
        int val; 
        int mini; 
        Node* next; 
        Node(int val,int mini,Node* next): val(val),mini(mini), next(next){}
    };
    Node* topPtr; 
public:
    MinStack() {
        topPtr = nullptr; 
    }
     
    void push(int val) {
        if (topPtr == nullptr) {
            topPtr = new Node(val,val,nullptr); 
        } else {
            int mn = min(val,topPtr->mini); 
            Node* newNode = new Node(val,mn,topPtr); 
            topPtr = newNode; 
        }
    }

    void pop() {
        Node* tmp = topPtr; 
        topPtr = topPtr->next; 
        delete tmp; 
    }
    
    int top() {
        return topPtr->val; 
    }
    
    int getMin() {
        return topPtr->mini; 
    }
};
