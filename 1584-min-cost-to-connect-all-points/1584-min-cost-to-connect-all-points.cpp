class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int sum=0;
        priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
    > pq;

    vector<int> vis(points.size(), 0);

    pq.push({0, 0});

    while(!pq.empty()){
        auto [dis, node] = pq.top();
        pq.pop();
        if (vis[node]){
            continue;
        }
        vis[node] = 1;
        sum+=dis;
        for (int next = 0; next < points.size(); next++) {

        if (vis[next]) continue;

        int wt = abs(points[node][0] - points[next][0]) +
                 abs(points[node][1] - points[next][1]);

        pq.push({wt, next});
    }
    }
    return sum;
    }
};