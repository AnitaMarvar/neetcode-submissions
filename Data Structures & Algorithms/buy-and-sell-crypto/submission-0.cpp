class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int minPrice = prices[0];

        for(int i=0;i<prices.size();i++)
        {
            minPrice = min(prices[i], minPrice);
            maxi = max(maxi, prices[i] - minPrice);
        }
        return maxi;
    }
};
