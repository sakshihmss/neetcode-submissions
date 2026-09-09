class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int l=1;l<=n;l++)
        {
            for(int i=0;i<n-l+1;i++)
            {
                int j = i+l-1;
                string word = s.substr(i, l);
                if(wordSet.find(word) != wordSet.end())
                {
                    dp[i][j] = true;
                }
                for(int k=i;k<j;k++)
                {
                    if(dp[i][k] == true && dp[k+1][j] == true)
                        dp[i][j] = true;
                }
            }
        }
        return dp[0][n-1];
    }
};
