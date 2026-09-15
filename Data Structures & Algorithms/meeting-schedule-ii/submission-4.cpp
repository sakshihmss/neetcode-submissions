/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> startTimes;
        vector<int> endTimes;
        int n = intervals.size();
        for(int i=0;i<n;i++)
        {
            startTimes.push_back(intervals[i].start);
            endTimes.push_back(intervals[i].end);
        }
        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());
        int ans = 0;
        int count = 0;
        int i = 0, j = 0;
        while(i < n && j < n)
        {
            if(startTimes[i] < endTimes[j])
            {
                count++;
                i++;
            }
            else
            {
                count--;
                j++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
