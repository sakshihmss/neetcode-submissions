class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n, 0);
        dp[0] = s[0] != '0' ? 1:0;
        if(n == 1)
            return dp[0];
        for(int i=1;i<n;i++)
        {
            cout<<i<<" "<<dp[i]<<endl;
            if(s[i] != '0')
                dp[i] += dp[i-1];
            cout<<i<<" "<<dp[i]<<endl;
            if(s[i-1] != '0' && s.substr(i-1, 2) <= "26")
                dp[i] += i == 1 ? 1 : dp[i-2];
            cout<<i<<" "<<dp[i]<<endl;
        }
        return dp[n-1];
    }
};
