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
        if((root->val > p->val && root->val <q->val) || (root->val > q->val && root->val < p->val))
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
