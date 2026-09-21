
class Solution {
private:
    bool fun(TreeNode* root, long long curmax, long long curmin)
    {
        if(root == nullptr) return true;

        if(root->val >= curmax || root->val <= curmin)
        {
            return false;
        }

        return fun(root->left, root->val, curmin)
            && fun(root->right, curmax, root->val);
    }

public:
    bool isValidBST(TreeNode* root) {
        return fun(root, LLONG_MAX, LLONG_MIN);
    }
};