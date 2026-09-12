class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        int count = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] =='1')
                {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';
                    while(!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++)
                        {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1')
                            {
                                grid[nx][ny] = '0';
                                q.push({nx, ny});
                            }
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
};
