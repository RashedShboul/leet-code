#include<iostream>
#include<map>
#include<unordered_map>
#include<unordered_set>
using namespace std; 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end()); 
        int c,r=0; 
        for (int x : nums) 
            if (!s.count(x-1)) {
                c = 1; 
                while (s.count(++x)) ++c; 
                r = max(r,c); 
            }
        return r; 
    }
};
int main() {
    int n; 
    cin >> n; 
    vector<int>v(n); 
    for (auto &x : v) cin >> x; 
    Solution s; 
    cout<< s.longestConsecutive(v) << endl;
    return 0; 
}