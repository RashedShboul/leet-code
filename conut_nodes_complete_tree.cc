#include <iostream>
#include <TreeNode.h>

using namespace std; 
class Solution {
public:
    int countNodes(TreeNode* root) {
        int leftCnt = 0, rightCnt = 0; 
        TreeNode* leftPtr = root; 
        TreeNode* rightPtr = root; 
        while (leftPtr) ++leftCnt, leftPtr = leftPtr->left; 
        while (rightPtr) ++rightCnt, rightPtr = rightPtr->right; 
        if (leftCnt == rightCnt) 
            return (1 << leftCnt) - 1; 
        else 
            return 1 + countNodes(root->right) + countNodes(root->left); 
    }
};