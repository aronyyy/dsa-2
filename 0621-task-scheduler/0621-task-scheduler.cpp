class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for(auto it: tasks){
            freq[it]++;
        }

        priority_queue<int> pq;
        for(auto it: freq){
            pq.push(it.second);
        }

        queue<pair<int, int>>q;

        int t = 0;
        while(!pq.empty() || !q.empty()){

            if(!pq.empty()){
                
                int count = pq.top()-1;
                pq.pop();
                if (count > 0) q.push({t + n, count});
                
            }

            if (q.front().first == t){
                pq.push(q.front().second);
                q.pop();
            }
            t++;
        }
        return t;
    }
};