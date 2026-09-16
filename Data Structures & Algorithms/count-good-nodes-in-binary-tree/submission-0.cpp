class Solution {
private:
    void fun(TreeNode* root, int& count, int maxVal) {

        if (root == nullptr)
            return;

        
        if (root->val >= maxVal)
            count++;

        maxVal = max(maxVal, root->val);

        fun(root->left, count, maxVal);
        fun(root->right, count, maxVal);
    }

public:
    int goodNodes(TreeNode* root) {

        if (root == nullptr)
            return 0;

        int count = 0;

        fun(root, count, root->val);

        return count;
    }
};