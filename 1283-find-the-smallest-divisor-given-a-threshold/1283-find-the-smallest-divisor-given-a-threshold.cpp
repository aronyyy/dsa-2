class Solution {
public:
    bool possible(vector<int>& arr, int thres, int k) {
        int cnt = 0;

        for (int num : arr) {
            cnt += (num + k - 1) / k;
        }

        return cnt <= thres;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(nums, threshold, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};