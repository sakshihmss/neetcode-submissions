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

class Codec {
public:

    void preOrder(TreeNode* root, string &ans)
    {
        if(!root)
            ans += "NULL:";
        else
        {
            ans += to_string(root->val) + ":";
            preOrder(root->left, ans);
            preOrder(root->right, ans);
        }
        return;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        preOrder(root, ans);
        ans.pop_back();
        return ans;
    }

    void preOrderDeserialize(vector<string> &tokens, int &i, TreeNode* &root)
    {
        if(tokens[i] == "NULL")
        {
            root = NULL;
            i++;
            return;
        }
        root = new TreeNode(stoi(tokens[i]));
        i++;
        preOrderDeserialize(tokens, i, root->left);
        preOrderDeserialize(tokens, i, root->right);
        return;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root;
        stringstream ss(data);
        vector<string> tokens;
        string token;
        while(getline(ss, token, ':'))
        {
            tokens.push_back(token);
        }
        int i = 0;
        preOrderDeserialize(tokens, i, root);
        return root;
    }
};
