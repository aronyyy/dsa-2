class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> string;
        for(auto it: s){
            if (isalnum(it)){
                string.push_back(tolower(it));
            }
        }
        int si = 0;
        int e = string.size() - 1;
        while (si < e){
            if (string[si++] != string[e--]) return false;
        }
        return true;
    }
};