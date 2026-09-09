class Solution {
public:
    void recurse(vector<int> &nums, int n, int index, int target, vector<int> &temp, vector<vector<int>>& ans)
    {
        if(target == 0)
        {
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for(int i=index;i<n;i++)
        {
            if(nums[i] <= target)
            {
                temp.push_back(nums[i]);
                recurse(nums, n, i, target-nums[i], temp, ans);
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        recurse(nums, n, 0, target, temp, ans);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
