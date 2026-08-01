class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;

        // Previous Smaller Element (strictly smaller)
        vector<int> pse(n);
        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                s.pop();
            }
            pse[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();

        // Next Smaller Element (smaller or equal)
        vector<int> nse(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop();
            }
            nse[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();

        // Previous Greater Element (strictly greater)
        vector<int> pge(n);
        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                s.pop();
            }
            pge[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();

        // Next Greater Element (greater or equal)
        vector<int> nge(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] <= nums[i]) {
                s.pop();
            }
            nge[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long maxContribution =
                1LL * nums[i] * (i - pge[i]) * (nge[i] - i);

            long long minContribution =
                1LL * nums[i] * (i - pse[i]) * (nse[i] - i);

            ans += maxContribution - minContribution;
        }

        return ans;
    }
};