
class Solution {
private:
    unordered_map<int, int> mp;
    int preIndex = 0;

    TreeNode* buildTreeHelper(vector<int>& preorder,
                              int inStart,
                              int inEnd)
    {
        // No elements in this subtree
        if(inStart > inEnd)
            return nullptr;

        // Pick root from preorder
        int rootVal = preorder[preIndex++];

        TreeNode* root = new TreeNode(rootVal);

        // Find root position in inorder
        int pos = mp[rootVal];

        // Build left subtree
        root->left = buildTreeHelper(preorder,
                                      inStart,
                                      pos - 1);

        // Build right subtree
        root->right = buildTreeHelper(preorder,
                                       pos + 1,
                                       inEnd);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder)
    {
        preIndex = 0;
        mp.clear();

        // Store inorder positions
        for(int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }

        return buildTreeHelper(preorder,
                               0,
                               inorder.size() - 1);
    }
};