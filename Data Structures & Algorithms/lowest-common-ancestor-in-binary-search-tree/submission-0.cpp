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
    bool isPresent(TreeNode* root, TreeNode* p)
    {
        if(root == p)
            return true;
        if(!root && !p)
            return true;
        if(!root)
            return false;
        return isPresent(root->left, p) || isPresent(root->right, p) || root == p;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q)
            return root;
        if(!root)
            return NULL;
        if(p && !q)
            return p;
        if(!p && q)
            return q;
        if(!p && !q)
            return NULL;
        if((isPresent(root->left, p) && isPresent(root->right, q)) || (isPresent(root->left, q) && isPresent(root->right, p)))
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left)
            return left;
        if (right)
            return right;
        return NULL;
    }
};
