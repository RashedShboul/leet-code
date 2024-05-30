#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addStrings(string n, string m) {
        int i = n.size()-1, j = m.size()-1,x,y,c=0; 
        string s; 
        while (i >= 0 && j >= 0) {
            x = n[i] - '0', y = m[j] - '0'; 
            int sum = x + y + c; 
            if (sum >= 10) {
                c = 1; 
                s += (sum%10) + '0'; 
            }
            else {
                s += sum + '0'; 
                c = 0; 
            }
            --j,--i; 
        }
        while (i >= 0) {s += (n[i--] - '0' + c) + '0'; c = 0;}   
        while (j >= 0) {s += (m[j--] - '0' + c) + '0'; c = 0;}
        if (c > 0) s += '1';    
        reverse(s.begin(), s.end()); 
        return s;
    }
};