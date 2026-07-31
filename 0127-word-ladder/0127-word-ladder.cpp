class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        queue<pair<string, int>>q;
        q.push({beginWord, 1});
        while(!q.empty()){
            string word = q.front().first;
            int dis = q.front().second;
            q.pop();
            if (word == endWord){
                return dis;
            }
            for (int i=0; i<word.size(); i++){
                char org = word[i];
                for (char j='a'; j<='z'; j++){
                    word[i] = j;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, dis+1});
                    }
                }
                word[i] = org;
            }

        }
        return 0;
    }
};