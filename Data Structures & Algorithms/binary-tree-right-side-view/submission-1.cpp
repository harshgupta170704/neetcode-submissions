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
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return {};
         vector<vector<int>>ans;
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int>v;
            while(n--)
            {
                auto x=q.front();
                q.pop();
                v.push_back(x->val);
                 if (x->left)
                    q.push(x->left);

                if (x->right)
                    q.push(x->right);
            }
            ans.push_back(v);
        }
        vector<int>a;
        for(int i=0;i<ans.size();i++)
        {
            a.push_back(ans[i].back());
        }
        return a;
    }
};
