#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include<queue>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> ends(deadends.begin(),deadends.end());
        queue<string> q;  
        
        if (ends.find("0000") != ends.end()); 
        q.push("0000"); 
         
        for (int i=0; !q.empty(); ++i) {
            int sz = q.size(); 
            while (sz--) {
            auto cur = q.front();
            q.pop(); 
            if(cur == target) return i;  
            vector<string> strs = helper(cur); 
            for (auto str : strs) {
                if (ends.count(str)) continue;
                q.push(str);
                ends.insert(str); 
                }
            }
        }
        return -1; 
    }

private:
    
   vector<string> helper(string s) { // construct the 8 possilbe choices for each string 
        vector<string> res; 
        string tmp; 
        for (int i=0; i<4; ++i) {
            tmp = s; 
            char c = s[i];  
            c = (c - '0' + 1) % 10 + '0';
            tmp[i] = c; 
            res.push_back(tmp); 
            c = (c - '0' - 2 + 10) % 10 + '0';
            tmp[i] = c; 
            res.push_back(tmp); 
        }
        
        return res; 
   }
};