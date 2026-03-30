class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int profit = 0;
        
        for(int i=0; i<prices.size()-1; ++i){
            if(prices[left] < prices[right]){
                profit = max(profit, (prices[right] - prices[left]));
            } else {
                left = right;
            }
            right++;
        }
        return profit;
    }
};
