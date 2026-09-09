class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> tails;
        for(int i=0;i<n;i++)
        {
            int lo = lower_bound(tails.begin(), tails.end(), nums[i]) - tails.begin();

            if(lo == tails.size())
            {
                tails.push_back(nums[i]);
            }
            else
            {   
                tails[lo] = nums[i];
            }
        }
        return tails.size();
    }
};
