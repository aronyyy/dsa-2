class Solution {
private:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis){
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && nrow < grid.size()
                    && ncol >= 0 && ncol < grid[0].size()
                    && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                        q.push({nrow, ncol});
                        vis[nrow][ncol] = 1;
                    }
            }
        }
        

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(r, vector<int>(c, 0));
        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                if (grid[i][j] == '1' && !vis[i][j]){
                    cnt++;
                    bfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};