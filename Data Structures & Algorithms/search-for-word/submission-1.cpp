class Solution {
public:
    bool dfs(vector<vector<char>>& board, int m, int n, int i, int j, string word, int l, int index, vector<vector<bool>> &visited)
    {
        if(index == l)
            return true;
        
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        for(int k=0;k<4;k++)
        {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && visited[nx][ny] == false && board[nx][ny] == word[index])
            {
                visited[nx][ny] = true;
                if(dfs(board, m, n, nx, ny, word, l, index+1, visited))
                    return true;
                visited[nx][ny] = false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int l = word.length();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == word[0])
                {
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    visited[i][j] = true;
                    if(dfs(board, m, n, i, j, word, l, 1, visited))
                        return true;
                }
            }
        }
        return false;
    }
};
