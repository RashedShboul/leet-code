#include<iostream>
#include<TreeNode.h>
#include<queue>
using namespace std; 

class Solution {
public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
            return new TreeNode(val, root, nullptr);
        queue<TreeNode *> q;
        q.push(root);
        int curDepth = 1;
        while (!q.empty())
        {
            if (curDepth == depth - 1)
            {
                int curSize = q.size();
                while (curSize--)
                {
                    TreeNode *curNode = q.front();
                    q.pop();
                    TreeNode *leftSubTree = curNode->left;
                    TreeNode *rightsubTree = curNode->right;
                    
                    curNode->left = new TreeNode(val,leftSubTree,nullptr); 
                    curNode->right = new TreeNode(val,nullptr,rightsubTree); 
                }
                break;
            }
            else
            {
                int curSize = q.size();
                while (curSize--)
                {
                    if (q.front()->left != nullptr)
                        q.push(q.front()->left);
                    if (q.front()->right != nullptr)
                        q.push(q.front()->right);
                    q.pop();
                }
                curDepth++;
            }
            
        }
        return root; 
    }
};