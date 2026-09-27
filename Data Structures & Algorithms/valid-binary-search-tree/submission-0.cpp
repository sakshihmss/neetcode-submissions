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
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        while(left && left->right)
        {
            left = left->right;
        }
        while(right && right->left)
        {
            right = right->left;
        }
        bool left_pass = true;
        bool right_pass = true;
        if(left)
            left_pass = left->val < root->val;
        if(right)
            right_pass = right->val > root->val;
        return left_pass && right_pass && isValidBST(root->left) && isValidBST(root->right);
    }
};
