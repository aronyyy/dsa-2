class Solution {
public:
    int dfs(vector<int>& prices, vector<vector<vector<int>>> &dp, int i, int t, int buy){
        if (i == prices.size() || t == 0){
            return 0;
        }
        if (dp[i][t][buy] != -1) return dp[i][t][buy];
        int profit = 0;
        if (t>0){
            if(buy == 1){
                profit = max(dfs(prices, dp, i+1, t, 0) - prices[i], dfs(prices, dp, i+1, t,  1));
            }
            else{
                profit = max(dfs(prices, dp, i+1, t-1, 1) + prices[i], dfs(prices, dp, i+1, t, 0));
            }
        }
        return dp[i][t][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, -1)));
        return dfs(prices, dp, 0, 2, 1);
    }
};