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
private: 
    bool fun(TreeNode* root, TreeNode* subroot)
    {
        if(root==nullptr && subroot==nullptr) return true;
        if(root==nullptr || subroot==nullptr) return false;
        if(root->val != subroot->val) return false;
        return fun(root->left,subroot->left)&& fun(root->right,subroot->right);

    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(subroot==nullptr) return true;
        if(root==nullptr) return false;
        if(fun(root,subroot)) return true;
         return isSubtree(root->left, subroot) ||
               isSubtree(root->right, subroot);
    }
};
