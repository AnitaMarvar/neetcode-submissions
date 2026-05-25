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
    void solve(TreeNode *root, vector<vector<int>>&ans)
    {
        if(root==NULL)return;

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            vector<int>level;
            while(sz--)
            {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            ans.push_back(level);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>>ans;
        vector<int>res;
        solve(root, ans);

        for(int i=0;i<ans.size();i++)
        {
            vector<int>arr = ans[i];
            reverse(arr.begin(),arr.end());
            int lastEle = arr[0];
            res.push_back(lastEle);
        }
        return res;
    }
};
