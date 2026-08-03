class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, 0);   
        int l= 0;
        int r = 0;
        int n = s.size();
        int maxi= 0;
        while(r<n){
            hash[s[r]]++;
            while(hash[s[r]] > 1){
                hash[s[l]]--;
                l++;
            }
            // if hash[s[r] > 1]{
            //     hash[s[l]]--;
            //     l++;
            // }
            int len = r - l + 1;
            maxi = max(maxi, len);
            
            r++;
        }
        return maxi;
    }
};