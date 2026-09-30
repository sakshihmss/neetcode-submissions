class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        vector<vector<int>> buckets(n+1);
        for(auto i:mp)
        {
            int val = i.second;
            buckets[val].push_back(i.first);
        }
        vector<int> ans;
        for(int i=n;i>=0;i--)
        {
            for(int j=0;j<buckets[i].size();j++)
            {
                ans.push_back(buckets[i][j]);
                if(ans.size() == k)
                    return ans;
            }
        }
        return ans;
    }
};
