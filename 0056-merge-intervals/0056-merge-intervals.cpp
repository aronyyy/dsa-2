class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] > b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {

            // Overlapping intervals
            if (intervals[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            // Non-overlapping interval
            else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};