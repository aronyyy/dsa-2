// class Solution {
// public:
//     int dfs(vector<int>& prices, vector<vector<int>> &dp ,int i, int buy){
//         if (i == prices.size()) return 0;
//         if (dp[i][buy] != -1) return dp[i][buy];

//         int profit;
//         if(buy == 1){
//             profit = max(dfs(prices, dp, i+1, 0) - prices[i], dfs(prices, dp, i+1, 1));
//         }
//         else {
//             profit = max(dfs(prices, dp,  i+1, 1) + prices[i], dfs(prices, dp, i+1, 0));
//         }
//         return dp[i][buy] = profit;
//     }
//     int maxProfit(vector<int>& prices) 
    
//     }
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // dp[i][buy]
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // dp[n][0] = dp[n][1] = 0 (already initialized)

        for (int i = n - 1; i >= 0; i--) {
            // buy == 1
            dp[i][1] = max(dp[i + 1][0] - prices[i],
                           dp[i + 1][1]);

            // buy == 0
            dp[i][0] = max(dp[i + 1][1] + prices[i],
                           dp[i + 1][0]);
        }

        return dp[0][1];
    }
};