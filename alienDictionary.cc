// Not leetcode problem
#include <algorithm>
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
private:
    unordered_map<char, int> mp; 
    bool helper(string s, string t) {
        int n = s.size(), m = t.size(); 
        int l = 0, r = 0; 
        while (l < n && r < m) {
            if (mp[s[l]] > mp[t[r]]) return true;
            else if (mp[s[l]] < mp[t[r]]) return false; 
            ++l; 
            ++r; 
        }
        return n >= m; 
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int cnt = 0; 
        for (char c : order) mp[c] = cnt++;
        for (int i=1; i<words.size(); ++i) {
            if (!helper(words[i], words[i-1])) return false;
        }
        return true; 
    }
};
int main() {
    return 0;
}