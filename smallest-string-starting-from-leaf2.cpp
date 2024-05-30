#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include"TreeNode.h"
using namespace std; 
class Solution {
private:  
    string dfs(TreeNode* root, string curStr) {
        if (!root)
            return; 
        curStr += 'a' + root->val; 
        if (root->left && root->right) {
            return min(dfs(root->left,curStr),dfs(root->right,curStr)); 
        }

        if (!root->left && !root->right) {
            
        }
              
    }
public:
    string smallestFromLeaf(TreeNode* root) {
         
    }
};

