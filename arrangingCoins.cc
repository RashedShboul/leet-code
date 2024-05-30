#include <iostream>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int cnt=0;while(cnt<=n)n-=cnt++;return cnt-1;  
    }
};