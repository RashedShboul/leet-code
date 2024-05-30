#include <iostream>
#include <vector>
using namespace std; 
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size()-1, m;  
        while (l <= r) {
            m = (r + l) / 2; 
            if (letters[m] <= target) l = m + 1;  
            else r = m - 1; 
        }
        return (l == letters.size() ? letters[0] : letters[l]); 
    }
};
