class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int first1 = 0;
        int second1 = nums[0];
        int curr1 = nums[0];
        for(int i=1;i<n-1;i++)
        {
            curr1 = max(first1 + nums[i], second1);
            first1 = second1;
            second1 = curr1;
        }
        cout<<curr1<<endl;
        int first2 = 0;
        int second2 = nums[n-1];
        int curr2 = nums[n-1];
        for(int i=n-2;i>=1;i--)
        {
            curr2 = max(first2 + nums[i], second2);
            first2 = second2;
            second2 = curr2;
        }
        return max(curr1, curr2);
    }
};
