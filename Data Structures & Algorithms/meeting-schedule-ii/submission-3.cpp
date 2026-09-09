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
    static bool comp(Interval i1, Interval i2)
    {
        return i1.start < i2.start;
    }

    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(pq.empty())
                pq.push(intervals[i].end);
            else
            {
                Interval curr = intervals[i];
                while(!pq.empty() && pq.top() <= curr.start)
                {
                    pq.pop();
                }
                pq.push(curr.end);
            }
            int sz = pq.size();
            ans = max(ans, sz);
        }
        return ans;
    }
};
