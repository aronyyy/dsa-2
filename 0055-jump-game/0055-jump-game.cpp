class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump=0;
        for (int i=0; i<nums.size(); i++){
            if (i == nums.size() - 1 && nums[i] == 0) return true;
            if (nums[i] == 0 && maxJump <= i){
                return false;
            }
            else {
                maxJump = max(maxJump, i + nums[i]);
            }
        }
        return true;
    }
};