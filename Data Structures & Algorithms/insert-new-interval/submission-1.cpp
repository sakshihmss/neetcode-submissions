class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        ans.push_back(newInterval);
        if(n == 0)
            return ans;
        for(int i=0;i<n;i++)
        {
            if(intervals[i][0] < ans.back()[0])
            {
                vector<int> temp = ans.back();
                ans.pop_back();
                if(intervals[i][1] < temp[0])
                {
                    ans.push_back(intervals[i]);
                    ans.push_back(temp);
                }
                else
                {
                    ans.push_back({intervals[i][0], max(intervals[i][1], temp[1])});
                }
            }
            else
            {
                if(ans.back()[1] < intervals[i][0])
                {
                    ans.push_back(intervals[i]);
                }
                else
                {
                    ans.back()[1] = max(intervals[i][1], ans.back()[1]);
                }
            }
        }
        return ans;
    }
};
