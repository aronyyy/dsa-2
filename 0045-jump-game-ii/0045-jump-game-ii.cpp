class Solution {
public:
    int dfs(vector<int>& nums, vector<int>& dp, int i) {

        if (i == 0)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MAX;

        for (int j = 0; j < i; j++) {
            if (j + nums[j] >= i) {
                ans = min(ans, 1 + dfs(nums, dp, j));
            }
        }

        return dp[i] = ans;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return dfs(nums, dp, n - 1);
    }
};