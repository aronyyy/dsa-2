class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const int MOD = 1e9 + 7;

        // Adjacency List
        vector<vector<pair<int, int>>> adj(n);

        for (auto &it : roads) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Min Heap -> {distance, node}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});
        int mod = (int)(1e9 + 7);
        while (!pq.empty()) {

            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Ignore stale entries
            if (dis > dist[node])
                continue;

            for (auto it : adj[node]) {

                int adjNode = it.first;
                int edgeWeight = it.second;

                // Found a shorter path
                if (dis + edgeWeight < dist[adjNode]) {

                    dist[adjNode] = dis + edgeWeight;

                    ways[adjNode] = ways[node];

                    pq.push({dist[adjNode], adjNode});
                }

                // Found another shortest path
                else if (dis + edgeWeight == dist[adjNode]) {

                    ways[adjNode] =
                        (ways[adjNode] + ways[node])%mod;
                }
            }
        }

        return ways[n - 1]%mod;
    }
};