#include <iostream>
#include <string>
#include <unordered_map>
using namespace std; 

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp; 
        unordered_map<string, char> strtochar; 
        int idx = 0; 
        string tmp = ""; 
        for (int i=0; i<s.size(); ++i) {
            if (s[i] != ' ') tmp += s[i]; 
            else {
                if (mp.find(pattern[idx]) != mp.end()) {
                    if (mp[pattern[idx]] != tmp || strtochar[tmp] != pattern[idx]) return false; 
                } 
                else {
                    mp[pattern[idx]] = tmp;
                    strtochar[tmp] = pattern[idx];
                }
                idx++; 
                tmp = ""; 
            }
        }
        return mp[pattern[idx]] == tmp && strtochar[tmp] == pattern[idx];
    }
};