// Not leetcode problem
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> shortestToChar(string s, char c) {
    int n = s.size(), pos = -n; 
    vector<int>res(n); 
    for (int i=0; i<n; ++i) {
        if(s[i] == c) pos = i; 
        res[i] = abs(i - pos); 
    }
    for (int i = n-1; i>=0; --i) {
        if (s[i] == c) pos = i; 
        res[i] = min(res[i], abs(i - pos)); 
    }
    return res;
  }
};
int main() {
  int n, t;
  cin >> n >> t;
  vector<int> v(n);
  for (int i = 0; i < n; ++i)
    cin >> v[i];
}