class Solution {
public:
    bool isOverlapping(vector<int> first, vector<int> second)
    {
        if (first[0] < second[0])
        {
            if(first[1] >= second[0])
                return true;
        }
        else
        {
            if(second[1] >= first[0])
                return true;
        }
        return false;
    }

    vector<int> overlap(vector<int> first, vector<int> second)
    {
        vector<int> res;
        res.push_back(min(first[0], second[0]));
        res.push_back(max(first[1], second[1]));
        return res;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ret;
        if(n == 0)
        {
            ret.push_back(newInterval);
            return ret;
        }
        int i = 0;
        vector<int> prev = newInterval;
        ret.push_back(prev);
        while(i < n)
        {
            if(isOverlapping(prev, intervals[i]))
            {
                ret.pop_back();
                prev = overlap(prev, intervals[i]);
                ret.push_back(prev);
            }
            else
            {
                if (prev[0] < intervals[i][0])
                {
                    ret.push_back(intervals[i]);
                    prev = intervals[i];
                }
                else
                {
                    ret.pop_back();
                    ret.push_back(intervals[i]);
                    ret.push_back(prev);
                }
            }
            i++;
        }
        return ret;
    }
};
