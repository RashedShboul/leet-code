#include<iostream>
#include<vector>
#include<algorithm>
#include"TreeNode.h"
using namespace std; 
class Solution {
private: 
    vector<string> res; 
    void dfs(TreeNode* root, string s) {
        char c = 'a'+root->val;
        if (!root->left && !root->right) { // if current node is leaf node 🤩🤩🤩
            s += c; 
            reverse(s.begin(),s.end()); 
            res.push_back(s); 
            return; 
        }
        if (root->left)
        dfs(root->left, s+c); 
        if (root->right)
        dfs(root->right, s+c); 
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        dfs(root,""); 
        auto minStr = min_element(res.begin(),res.end()); 
        return *minStr; 
    }
};

