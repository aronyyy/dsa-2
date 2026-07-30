class Solution {
public:
    bool dfs(int node, int clr, vector<vector<int>>& graph, vector<int> &vis){
        vis[node] = clr;
        for (auto it: graph[node]){
            if (vis[it]==0){
                if (dfs(it, clr*(-1), graph, vis)){
                    return true;
                }
            }
            else if (vis[it] == clr){
                return true;
            }
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        for (int i=0; i<n; i++){
            if (vis[i]==0){
                if (dfs(i, 1, graph, vis)){
                    return false;
                }
            }
        }
        return true;
    }
};