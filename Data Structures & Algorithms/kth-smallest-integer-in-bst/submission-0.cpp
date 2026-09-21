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
    void  fun(TreeNode* root, int k,vector<int>&order)
    {

        if(root==nullptr) return ;
        order.push_back(root->val);
        fun(root->left,k,order);
        fun(root->right,k,order);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>order;
        fun(root,k,order);
        sort(order.begin(),order.end());
        return order[k-1];
    }
};
