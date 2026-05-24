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
    int solve(TreeNode *root, int &maxi)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lefty = 1 + solve(root->left, maxi);
        int righty = 1 + solve(root->right,maxi);
        return max(lefty , righty);
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;

        int maxi = -1;
        return solve(root, maxi);
    }
};
