#include <iostream>
#include <string>
#include <vector>
using namespace std; 

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res; 
        int i = 0, j = 0;  
        while (i < nums.size()) {
            while (i < nums.size()-1 && nums[i+1] - nums[i] <= 1) ++i; 
            string tmp; 
            if (i - j > 0) {
                tmp += to_string(nums[j]) + "->" + to_string(nums[i]); 
                res.push_back(tmp); 
            }
            else {
                tmp += to_string(nums[j]);  
                res.push_back((tmp)); 
            }
            i += 1;
            j = i;  
        }
        return res;
    }
};