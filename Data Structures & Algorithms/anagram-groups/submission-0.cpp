class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        for(int i=0;i<n;i++)
        {
            string curr = strs[i];
            sort(curr.begin(), curr.end());
            mp[curr].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto i:mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};
