class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l=0;
        int r=0;
        unordered_map<char, int>mpp;
        int maxF=0;
        int ans = 0;
        while(r<n){
            mpp[s[r]]++;
            maxF = max(maxF, mpp[s[r]]);
            while(maxF < r-l+1-k){
                mpp[s[l]]--;
                l++;
            }
            r++;
            ans = max(r-l+1, ans);
        }
        return ans-1;
    }
};