class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int minCurr = 1;
        int maxCurr = 1;
        for(int i=0;i<n;i++)
        {
            int val1 = minCurr*nums[i];
            int val2 = maxCurr*nums[i];

            minCurr = min(nums[i], min(val1, val2));
            maxCurr = max(nums[i], max(val1, val2));

            ans = max(ans, maxCurr);
        }
        return ans;
    }
};
