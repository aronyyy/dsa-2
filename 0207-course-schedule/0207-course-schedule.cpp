class Solution {
public:
    bool dfs(int i, vector<vector<int>>& adj, vector<int>& vis, vector<int>& path){
        vis[i] = 1;
        path[i] = 1;
        for (auto it: adj[i]){
            if (!vis[it]){
                if (dfs(it, adj, vis, path)){

                    return true;
                }
            }
            else if (path[it]){
                return true;
            }
        }
        path[i] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &it : prerequisites) {

            int course = it[0];
            int prereq = it[1];

            adj[prereq].push_back(course);
        }

        vector<int> vis(numCourses, 0);
        vector<int> path(numCourses, 0);

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