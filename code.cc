// Not leetcode problem
#include <algorithm>
#include <cctype>
#include <iostream>
#include <queue>
#include <random>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <cmath>
#include "TreeNode.h"
using namespace std;
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int freq[26] = {0}; 
        string ans = "";

        for (char c : licensePlate) {
            if (isalpha(c)) {
                ++freq[tolower(c) - 'a']; 
            }
        }

        for (string &w : words) {
            int f2[26]; 
            for (char c : w) ++f2[c - 'a']; 

            bool valid = true;
            for (int i = 0; i < 26; ++i) {
                if (freq[i] > f2[i]) {  
                    valid = false;
                    break;
                }
            }
            
            if (valid && (ans.empty() || w.size() < ans.size()))
                ans = w; 
        }
        return ans;
    }
};
int main() {
    return 0;
}