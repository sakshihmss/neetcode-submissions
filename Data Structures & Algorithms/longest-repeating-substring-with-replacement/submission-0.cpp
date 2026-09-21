class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<char, int> mp;
        int i = 0, j = 0;
        int maxCount = 0;
        int maxLen = 0;
        while(j < n)
        {
            mp[s[j]]++;
            maxCount = max(maxCount, mp[s[j]]);
            if(maxCount + k >= j-i+1)
                maxLen = max(maxLen, j-i+1);
            else
            {
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return maxLen;
    }
};
