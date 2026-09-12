class Solution {
public:
    void bfs(queue<pair<int, int>> q, vector<vector<int>> &ocean, vector<vector<int>>& heights, int m, int n)
    {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && ocean[nx][ny] != 1 && heights[nx][ny] >= heights[x][y])
                {
                    ocean[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> ans;
        
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        queue<pair<int, int>> q_pacific;
        queue<pair<int, int>> q_atlantic;
        for(int i=0;i<m;i++)
        {
            pacific[i][0] = 1;
            q_pacific.push({i, 0});
            atlantic[i][n-1] = 1;
            q_atlantic.push({i, n-1});
        }
        for(int j=0;j<n;j++)
        {
            pacific[0][j] = 1;
            q_pacific.push({0, j});
            atlantic[m-1][j] = 1;
            q_atlantic.push({m-1, j});
        }
        bfs(q_pacific, pacific, heights, m, n);
        bfs(q_atlantic, atlantic, heights, m, n);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pacific[i][j] == 1 && atlantic[i][j] == 1)
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
