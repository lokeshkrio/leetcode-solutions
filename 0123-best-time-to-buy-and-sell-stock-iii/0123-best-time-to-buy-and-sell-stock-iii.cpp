class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p1 = -prices[0], p2 = 0, p3 = -prices[0], p4 = 0;
        for (int i = 1; i < prices.size(); ++i) {
            p1 = max(p1, -prices[i]);
            p2 = max(p2, p1 + prices[i]);
            p3 = max(p3, p2 - prices[i]);
            p4 = max(p4, p3 + prices[i]);
        }
        return p4;
    }
};