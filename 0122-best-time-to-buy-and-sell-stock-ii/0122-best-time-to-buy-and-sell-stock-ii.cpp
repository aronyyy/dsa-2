class Solution {
public:
    int dfs(vector<int>& prices, vector<vector<int>> &dp ,int i, int buy){
        if (i == prices.size()) return 0;
        if (dp[i][buy] != -1) return dp[i][buy];

        int profit;
        if(buy == 1){
            profit = max(dfs(prices, dp, i+1, 0) - prices[i], dfs(prices, dp, i+1, 1));
        }
        else {
            profit = max(dfs(prices, dp,  i+1, 1) + prices[i], dfs(prices, dp, i+1, 0));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return dfs(prices, dp, 0, true);
    }
};