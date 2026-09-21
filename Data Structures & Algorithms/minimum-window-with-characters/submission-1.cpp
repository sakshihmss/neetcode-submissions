class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(n > m)
            return "";
        unordered_map<char, int> mp_s;
        unordered_map<char, int> mp_t;
        for(int i=0;i<n;i++)
            mp_t[t[i]]++;
        int i = 0, j = 0;
        int start = 0, len = INT_MAX, count = 0;
        while(j < m)
        {
            mp_s[s[j]]++;
            if(mp_t.find(s[j]) != mp_t.end() && mp_t[s[j]] == mp_s[s[j]])
                count++;
            if (count == mp_t.size())
            {
                while(i < j && (mp_t.find(s[i]) == mp_t.end() || mp_t[s[i]] < mp_s[s[i]]))
                {
                    mp_s[s[i]]--;
                    i++;
                }
                if(len > j-i+1)
                {
                    start = i;
                    len = j-i+1;
                }
            }
            j++;
        }
        if (count == mp_t.size())
        {
            while(i < j && (mp_t.find(s[i]) == mp_t.end() || mp_t[s[i]] < mp_s[s[i]]))
            {
                mp_s[s[i]]--;
                i++;
            }
            if(len > j-i)
            {
                start = i;
                len = j-i;
            }
        }
        return len == INT_MAX ? "":s.substr(start, len);
    }
};
