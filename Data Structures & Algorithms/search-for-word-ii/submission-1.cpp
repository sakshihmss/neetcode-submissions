struct TrieNode{
    TrieNode* children[26];
    bool isEndOfWord;
    string word;
    TrieNode(): isEndOfWord(false){
        for(int i=0;i<26;i++)
            children[i] = NULL;
    }
};

class Solution {
public:
    TrieNode* root;
    Solution()
    {
        root = new TrieNode();
    }

    void insert(TrieNode* curr, string word)
    {
        int n = word.length();
        for(int i=0;i<n;i++)
        {
            int idx = word[i] - 'a';
            if(curr->children[idx] == NULL)
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->word = word;
        curr->isEndOfWord = true;
        return;
    }

    bool search(TrieNode* curr, string word)
    {
        int n = word.length();
        for(int i=0;i<n;i++)
        {
            int idx = word[i] - 'a';
            if(curr->children[idx] == NULL)
                return false;
            curr = curr->children[idx];
        }
        return curr->isEndOfWord;
    }

    void helper(vector<vector<char>> & board, int m, int n, int i, int j, TrieNode* curr, unordered_set<string> &ans, vector<vector<bool>> &visited)
    {
        if(curr->isEndOfWord == true)
        {
            ans.insert(curr->word);
        }
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        for(int k=0;k<4;k++)
        {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny])
            {
                int idx = board[nx][ny] - 'a';
                if(curr->children[idx] == NULL)
                    continue;
                visited[nx][ny] = true;
                helper(board, m, n, nx, ny, curr->children[idx], ans, visited);
                visited[nx][ny] = false;
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int l = words.size();
        for(int i=0;i<l;i++)
        {
            insert(root, words[i]);
        }
        unordered_set<string> vec;
        vector<string> ans;
        int m = board.size();
        if(m == 0)
            return vector<string>();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int idx = board[i][j] - 'a';
                if(root->children[idx] == NULL)
                    continue;
                visited[i][j] = true;
                helper(board, m, n, i, j, root->children[idx], vec, visited);
                visited[i][j] = false;
            }
        }
        for(auto i:vec)
        {
            ans.push_back(i);
        }
        return ans;
    }
};
