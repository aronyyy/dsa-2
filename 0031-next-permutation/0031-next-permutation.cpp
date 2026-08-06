class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find the pivot
        int pivot = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // Step 2: If pivot exists, swap with the next greater element
        if (pivot != -1) {
            for (int i = n - 1; i > pivot; i--) {
                if (nums[i] > nums[pivot]) {
                    swap(nums[i], nums[pivot]);
                    break;
                }
            }
        }

        // Step 3: Reverse the suffix
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};