class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        string ans = "";
        int index = 0, len = 0;
        for(int i=0;i<n;i++)
        {
            dp[i][i] = 1;
            index = i;
            len = 1;
        }
        for(int i=0;i<n-1;i++)
        {
            dp[i][i+1] = s[i] == s[i+1] ? 1:0;
            if(dp[i][i+1] == 1)
            {
                index = i;
                len = 2;
            }
        }
        for(int l=3;l<=n;l++)
        {
            for(int i=0;i<n-l+1;i++)
            {
                int j = i+l-1;
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1];
                if(dp[i][j] == 1)
                {
                    index = i;
                    len = l;
                }
            }
        }
        return s.substr(index, len);
    }
};
