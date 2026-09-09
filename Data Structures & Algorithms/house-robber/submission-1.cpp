class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int first = nums[0];
        if(n == 1)
            return first;
        int second = max(nums[0], nums[1]);
        if(n == 2)
            return second;
        int curr = 0;
        for(int i=2;i<n;i++)
        {
            curr = max(first + nums[i], second);
            first = second;
            second = curr;
        }
        return curr;
    }
};
