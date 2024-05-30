#include <iostream>
#include<vecintrin.h>
#include <unordered_set>

using namespace std; 
class Solution {
private: 
    int calc(int n) {
        int ans = 0; 
        while (n) {
            int x = n % 10; 
            ans += x * x; 
            n /= 10; 
        }
        return ans; 
    }
public:
    bool isHappy(int n) {
        while (n != 4) {
            n = calc(n); 
            if (n == 1) return true; 
        }
        return false; 
    }
};