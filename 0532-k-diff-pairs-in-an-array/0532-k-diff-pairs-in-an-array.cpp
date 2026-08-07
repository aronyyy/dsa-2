class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(auto it: nums){
            mp[it]++;
        }
        int ans=0;
        if (k==0){
            for (auto it: mp){
                if (it.second > 1){
                    ans++;
                }
            }
            return ans;
        }
        
        for(auto it: mp){
            if (mp.find(it.first + k) != mp.end()){
                ans++;
            }
        }
        return ans;
    }
};