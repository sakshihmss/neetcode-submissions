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
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        auto comp = [](Interval i1, Interval i2)
        {
            if(i1.start == i2.start)
                return i1.end < i2.end;
            return i1.start < i2.start;
        };
        sort(intervals.begin(), intervals.end(), comp);
        for(int i=0;i<n-1;i++)
        {
            if(intervals[i].end > intervals[i+1].start)
                return false;
        }
        return true;
    }
};
