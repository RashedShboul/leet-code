#include<iostream>
#include<vector>
using namespace std; 

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; 
        if (n == 2) return max(nums[0],nums[1]); 
        
        for (int i=3; i<n; ++i) {
            if (nums[i] >= x) z=y, y=x, x=nums[i]; 
            if (nums[i] >= y) z=y, y=nums[i]; 
            if (nums[i] >= z) z=nums[i]; 
        }
        if (x != y && x != z) return z; 
        return x; 
    }
};