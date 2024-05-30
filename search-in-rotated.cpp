#include <iostream>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size(), r = n - 1, l = 0, mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            // search in left portion of the array after rotating
            if (nums[l] <= nums[mid]) {
                if (target > nums[mid] || target < nums[l])
                    l = mid + 1; 
                else 
                    r = mid - 1; 
            }
            // search in right portion of the array after rotating
            else {
                if (target < nums[mid] || target > nums[r])
                    r = mid - 1; 
                else 
                    l = mid + 1;    
            }
            
        }   
        return -1; 
    }
};