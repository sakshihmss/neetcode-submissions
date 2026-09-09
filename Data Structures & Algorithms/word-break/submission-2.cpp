class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(n, false);
        for(int i=0;i<n;i++)
        {
            string word = s.substr(0, i+1);
            if(wordSet.find(word) != wordSet.end())
                dp[i] = true;
            else
            {
                for(int j=0;j<=i;j++)
                {
                    string word = s.substr(j+1, i-j);
                    if(dp[j] == true && wordSet.find(word) != wordSet.end())
                        dp[i] = true;
                }
            }
        }
        return dp[n-1];
    }
};
