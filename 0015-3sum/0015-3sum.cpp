class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i=0; i<n; i++){
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l=i+1;
            int h=n-1;
            while(l<h){
                int sum = nums[l] + nums[h] + nums[i];
                if (sum == 0){
                    ans.push_back({nums[i], nums[l], nums[h]});
                    l++;
                    h--;
                    while (l < h && nums[l] == nums[l - 1])
                        l++;

                    while (l < h && nums[h] == nums[h + 1])
                        h--;
                }
                else if (sum < 0){
                    l++;
                }
                else{
                    h--;
                }
                
            }
        }
        return ans;
    }
};