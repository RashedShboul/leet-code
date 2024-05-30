#include<iostream>
#include<vector>
using namespace std; 

class Solution {
public:
    int tribonacci(int n) {
        int arr[38] = {0,1}; 
        for (int i=1; i<38; ++i)   
            arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
        return arr[n];  
    }
};