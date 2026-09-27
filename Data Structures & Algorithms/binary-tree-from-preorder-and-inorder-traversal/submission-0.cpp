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
    int findIndex(vector<int> &inorder, int start, int end, int root)
    {
        for(int i=start;i<=end;i++)
        {
            if(inorder[i] == root)
                return i;
        }
        return -1;
    }

    TreeNode* build(vector<int>& preorder, int start_pre, int end_pre, vector<int>& inorder, int start_in, int end_in)
    {
        if(start_pre > end_pre || start_in > end_in)
            return NULL;
        int val = preorder[start_pre];
        TreeNode* root = new TreeNode(val);
        int index = findIndex(inorder, start_in, end_in, val);
        int actual_index = index - start_in;
        root->left = build(preorder, start_pre+1, start_pre+actual_index, inorder, start_in, index-1);
        root->right = build(preorder, start_pre+actual_index+1, end_pre, inorder, index+1, end_in);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n == 0)
            return NULL;
        return build(preorder, 0, n-1, inorder, 0, n-1);
    }
};
