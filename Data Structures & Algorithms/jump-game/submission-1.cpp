class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return true;
        int maxIndex = nums[0];
        for(int i=0;i<n;i++)
        {
            maxIndex = max(maxIndex, i + nums[i]);
            if(maxIndex >= n-1)
                return true;
            if(maxIndex == i)
                return false;
        }
        return false;
    }
};
