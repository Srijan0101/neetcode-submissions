class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0, min_price = INT_MAX;
        for(auto it : prices){

            min_price = min(min_price, it);
            profit = max(profit, it-min_price);
        }

        return profit;
    }
};
