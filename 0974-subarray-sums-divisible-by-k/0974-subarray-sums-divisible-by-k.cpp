class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> freq(k, 0);
        freq[0] = 1;
        int ans=0;
        int prefix = 0;
        for(auto it: nums){
            prefix += it;
            int rem = ((prefix%k) + k)%k;
            ans += freq[rem];
            freq[rem]++;
        }
        return ans;
    }
};