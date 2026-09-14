class Solution {
private:
    bool fun(TreeNode* p, TreeNode* q)
    {
        // Both are NULL -> same
        if(p == nullptr && q == nullptr)
            return true;

        // One is NULL -> different
        if(p == nullptr || q == nullptr)
            return false;

        // Values are different
        if(p->val != q->val)
            return false;

        // Check left subtree
        if(fun(p->left, q->left) == false)
            return false;

        // Check right subtree
        if(fun(p->right, q->right) == false)
            return false;

        return true;
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        return fun(p, q);
    }
};