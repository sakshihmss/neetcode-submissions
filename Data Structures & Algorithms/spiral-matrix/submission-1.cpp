class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int dir = 0; // 0: right, 1: down, 2:left, 3:up
        int i = 0, j = 0;
        int left = 0, right = n-1, top = 0, bottom = m-1;
        while(left <= right && top <= bottom)
        {
            if(dir == 0)
            {
                for(int j=left;j<=right;j++)
                {
                    ans.push_back(matrix[top][j]);
                }
                top++;
                dir++;
            }
            else if(dir == 1)
            {
                for(int i=top;i<=bottom;i++)
                {
                    ans.push_back(matrix[i][right]);
                }
                right--;
                dir++;
            }
            else if(dir == 2)
            {
                for(int j=right;j>=left;j--)
                {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
                dir++;
            }
            else if(dir == 3)
            {
                for(int i=bottom;i>=top;i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
                dir = 0;
            }
        }
        return ans;
    }
};
