class Solution {
private:
    TreeNode* fun(TreeNode* root)
    {
        if (root == nullptr)
            return nullptr;

        // Create a new node for the 2nd tree
        TreeNode* root1 = new TreeNode(root->val);

        // Your same logic: swap left and right
        root1->left = fun(root->right);
        root1->right = fun(root->left);

        return root1;
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        return fun(root);
    }
};