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
    int maxPath(TreeNode* root, int &ans)
    {
        if(!root)
            return 0;
        if(!root->left && !root->right)
        {
            ans = max(ans, root->val);
            return root->val;
        }
        int l = maxPath(root->left, ans);
        int r = maxPath(root->right, ans);
        ans = max(ans, max(0, l) + max(0, r) + root->val);
        return max(0, max(l, r)) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        int ans = INT_MIN;
        maxPath(root, ans);
        return ans;
    }
};
