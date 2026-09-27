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
    TreeNode* build(vector<int>& preorder, int start_pre, int end_pre, vector<int>& inorder, int start_in, int end_in, unordered_map<int, int> &mp)
    {
        if(start_pre > end_pre || start_in > end_in)
            return NULL;
        int val = preorder[start_pre];
        TreeNode* root = new TreeNode(val);
        int index = mp[val];
        int actual_index = index - start_in;
        root->left = build(preorder, start_pre+1, start_pre+actual_index, inorder, start_in, index-1, mp);
        root->right = build(preorder, start_pre+actual_index+1, end_pre, inorder, index+1, end_in, mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n == 0)
            return NULL;
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++)
            mp[inorder[i]] = i;
        return build(preorder, 0, n-1, inorder, 0, n-1, mp);
    }
};
