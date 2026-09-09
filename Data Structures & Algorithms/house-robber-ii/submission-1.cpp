class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0], nums[1]);
        if(n == 3)
            return max(nums[0], max(nums[1], nums[2]));
        int first1 = nums[0];
        int second1 = max(nums[0], nums[1]);
        int curr1 = 0;
        for(int i=2;i<n-1;i++)
        {
            curr1 = max(first1 + nums[i], second1);
            first1 = second1;
            second1 = curr1;
        }
        cout<<curr1<<endl;
        int first2 = nums[n-1];
        int second2 = max(nums[n-1], nums[n-2]);
        int curr2 = 0;
        for(int i=n-3;i>=1;i--)
        {
            curr2 = max(first2 + nums[i], second2);
            first2 = second2;
            second2 = curr2;
        }
        cout<<curr2<<endl;
        return max(curr1, curr2);
    }
};
