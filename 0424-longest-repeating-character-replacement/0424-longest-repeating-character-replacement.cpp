class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxL = 0;
        int l=0;
        int r=0;
        int maxF = 0;
        unordered_map<char, int> mp;
        while(r < n){
            mp[s[r]]++;
            maxF = max(maxF, mp[s[r]]);
            int changes = r - l + 1 - maxF;

            while(changes > k){
                mp[s[l]]--;
                maxF = 0;
                for(auto it: mp){
                    maxF = max(maxF, it.second);
                }
                l++;
                changes = r - l + 1 - maxF;
            }

            maxL = max(maxL, r-l+1);
            r++;
        }
        return maxL;
    }

};