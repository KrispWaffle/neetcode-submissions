class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int bestPrice{-1};
        int buy{prices[0]};

        for (int i{0}; i < prices.size(); i++) {
            buy = std::min(buy, prices[i]);
            bestPrice = std::max(bestPrice, (prices[i] - buy));
        }
        return bestPrice;
    }
};
