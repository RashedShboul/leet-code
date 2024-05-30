#include <iostream>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> st, ts;
        for (int i=0; i<s.size(); ++i) {
            if (st.find(s[i]) == st.end() && ts.find(t[i]) == ts.end()) {
                st[s[i]] = t[i]; 
                ts[t[i]] = s[i]; 
            } else {
                if (st[s[i]] != t[i] || ts[t[i]] != s[i]) return 0; 
            }
        }
        return 1; 
    }
};