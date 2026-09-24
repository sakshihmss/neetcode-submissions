class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string encoded = "";
        for(int i=0;i<n;i++)
        {
            int m = strs[i].length();
            encoded += to_string(m) + "#" + strs[i];
        }
        return encoded;
    }

    vector<string> decode(string s) {
        int n = s.length();
        vector<string> decoded;
        int i = 0;
        while(i < n)
        {
            string num = "";
            while(i < n && s[i] != '#')
            {
                num += s[i];
                i++;
            }
            i++;
            int len = stoi(num);
            string curr = "";
            for(int j=0;j<len;j++)
            {
                curr += s[i];
                i++;
            }
            decoded.push_back(curr);
        }
        return decoded;
    }
};
