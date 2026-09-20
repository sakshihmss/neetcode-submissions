class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0)
            return 0;
        unordered_set<int> st;
        int i = 0, j = 0;
        int maxLen = 0;
        while(j < n)
        {
            if(st.find(s[j]) != st.end())
            {
                while(i < j && s[i] != s[j])
                {
                    st.erase(s[i]);
                    i++;
                }
                i++;
                st.insert(s[j]);
            }
            else
            {
                st.insert(s[j]);
            }
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};
