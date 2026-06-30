class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> adjRev(graph.size());
        vector<int> inDegree(graph.size());
        for (int i=0; i<graph.size(); i++){
            for (auto it: graph[i]){
                adjRev[it].push_back(i);
                inDegree[i]++;
            }
        }
        queue<int> q;
        for (int i=0; i<graph.size(); i++){
            if (inDegree[i]==0){
                q.push(i);
            }
        }
        vector<int> safe;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe.push_back(node);
            for(auto it: adjRev[node]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);

                }
            }
        }
        sort(safe.begin(), safe.end());
        return safe;

    }
};