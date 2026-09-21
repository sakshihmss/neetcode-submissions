class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.length();
        int n = t.length();
        unordered_map<char, int> mp_s;
        unordered_map<char, int> mp_t;
        for(int i=0;i<m;i++)
            mp_s[s[i]]++;
        for(int i=0;i<n;i++)
            mp_t[t[i]]++;
        return mp_s == mp_t;
    }
};
