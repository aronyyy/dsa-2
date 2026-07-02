class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> time(n+1, 1e9);
        time[k] = 0;
        priority_queue<pair<int, int>,
                    vector<pair<int, int>>,
                    greater<pair<int, int>>> pq;
        pq.push({0, k});
        while(!pq.empty()){
            int node = pq.top().second;
            int tm = pq.top().first;
            pq.pop();
            for (auto it: adj[node]){
                int val = it.first;
                int etm = it.second;
                if (tm + etm < time[val]){
                    time[val] = tm+etm;
                    pq.push({time[val], val});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){

            if(time[i] == 1e9)
                return -1;

            ans = max(ans, time[i]);
        }

        return ans;
    }

};