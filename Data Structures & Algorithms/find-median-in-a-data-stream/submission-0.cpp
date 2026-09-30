class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    int count;
    MedianFinder() {
        count = 0;
    }
    
    void addNum(int num) {
        if(left.empty())
            left.push(num);
        else
        {
            if(left.top() > num)
                left.push(num);
            else
                right.push(num);
        }
        if(left.size() > right.size() + 1)
        {
            int val = left.top();
            left.pop();
            right.push(val);
        }
        if(right.size() > left.size())
        {
            int val = right.top();
            right.pop();
            left.push(val);
        }
        count++;
        return;
    }
    
    double findMedian() {
        if(count%2 == 1)
            return left.top();
        else
        {
            return (left.top() + right.top())/2.0;
        }
    }
};
