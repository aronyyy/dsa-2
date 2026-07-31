class Solution {
public:
    bool dfs(int node, vector<vector<int>>&adj, vector<int>& vis, vector<int>& path){
        vis[node] = 1;
        path[node] = 1;

        for(auto it: adj[node]){
            if (!vis[it] && dfs(it, adj, vis, path)){
                return true;
            }
            else{
                if (path[it]){
                    return true;
                }
            }
        }
        path[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &it : prerequisites) {

            int course = it[0];
            int prereq = it[1];

            adj[prereq].push_back(course);
        }
        vector<int> vis(numCourses);
        vector<int> path(numCourses);
        for (int i=0; i<numCourses; i++){
            if (!vis[i]){
                if (dfs(i, adj, vis, path)){
                    return false;
                }
            }
        }
        return true;

    }
};