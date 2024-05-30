// Not leetcode problem
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char, int>charToIdx; //char -> index of first occurence 
        for (int i=0; i<s.size(); ++i)
            if (charToIdx.find(s[i]) == charToIdx.end()) charToIdx[s[i]] = i; 
            else if (i - charToIdx[s[i]] - 1 != distance[s[i] - 'a']) return false; 
        return true;
    }
};
int main() {return 0;}