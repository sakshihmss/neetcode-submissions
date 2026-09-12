class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;
        int curr = 0;
        for(int i=0;i<n;i++)
        {
            if(s.find(nums[i]-1) == s.end())
            {
                int num = nums[i];
                curr = 0;
                while(s.find(num) != s.end())
                {   
                    curr++;
                    num++;
                }
                longest = max(longest, curr);
            }
        }
        return longest;
    }
};
