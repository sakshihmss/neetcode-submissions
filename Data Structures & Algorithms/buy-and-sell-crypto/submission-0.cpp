class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1)
            return 0;
        int maxProfit = 0;
        int minPrice = INT_MAX;
        for(int i=0;i<n;i++)
        {
            minPrice = min(minPrice, prices[i]);
            if(prices[i] > minPrice)
                maxProfit = max(maxProfit, prices[i]-minPrice);
        }
        return maxProfit;
    }
};
