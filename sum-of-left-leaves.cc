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
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0; 
        queue<TreeNode*> q; 
        q.push(root); 
        while (!q.empty()) {
            TreeNode* curNode = q.front(); 
            q.pop(); 
            if (curNode->left) {
                if (!curNode->left->left && !curNode->left->right)
                    sum += curNode->left->val;
                q.push(curNode->left); 
            }
            if (curNode->right) q.push(curNode->right); 
        }
        return sum; 
    }
};
int main() {
    return 0;
}