
//keep just a k elements in the queue 
#include<iostream>
#include<queue>
using namespace std; 

class KthLargest {
private: 
    int k; 
    priority_queue<int, vector<int>, greater<int>> pq; 
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k; 
        for (int x : nums) 
            this->add(x);   
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) 
            pq.pop(); 
        return pq.top(); 
    }
};

int main() {
    vector<int> v {5,6,7,43,45,9}; 
    KthLargest sol(); 
    return 0; 
}