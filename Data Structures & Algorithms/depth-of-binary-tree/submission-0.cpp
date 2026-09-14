/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int fun(TreeNode* root)
    {
        
        if(root==nullptr) return 0;
        int maxi=0;
        maxi=max(fun(root->right),fun(root->left))+1;
        
        return maxi;

    }
public:
    int maxDepth(TreeNode* root) {
        int max=0;
        return fun(root);
        
    }
};
