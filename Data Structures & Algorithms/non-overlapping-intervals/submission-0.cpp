class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto comp = [](vector<int> interval1, vector<int> interval2){
            if(interval1[1] == interval2[1])
                return interval1[0] <= interval2[0];
            return interval1[1] < interval2[1];
        };
        sort(intervals.begin(), intervals.end(), comp);
        int n = intervals.size();
        vector<vector<int>> nonOverlapping;
        nonOverlapping.push_back(intervals[0]);
        int count = 0;
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0] >= nonOverlapping.back()[1])
            {
                nonOverlapping.push_back(intervals[i]);
            }
            else
            {
                count++;
            }
        }
        return count;
    }
};
