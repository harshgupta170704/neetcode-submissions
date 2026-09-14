class Solution {
private:
    int fun(TreeNode* root, int &diff)
    {
        if(root == nullptr)
            return 0;

        int left = fun(root->left, diff);
        int right = fun(root->right, diff);

        diff = max(diff, abs(left - right));

        return 1 + max(left, right);
    }

public:
    bool isBalanced(TreeNode* root) {
        int diff = 0;

        fun(root, diff);

        if(diff > 1)
            return false;

        return true;
    }
};