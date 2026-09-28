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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        int count = 0;
        while(root || !s.empty())
        {
            if(root)
            {
                s.push(root);
                root = root->left;
            }
            else
            {
                TreeNode* node = s.top();
                s.pop();
                count++;
                if(count == k)
                    return node->val;
                root = node->right;
            }
        }
        return -1;
    }
};
