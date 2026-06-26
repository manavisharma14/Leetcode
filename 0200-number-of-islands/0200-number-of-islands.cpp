class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        int islands = 0;

        queue<pair<int,int>>q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    islands++;
                    q.push({i,j});
                    visited[i][j] = true;

                    // bfs here
                    // explore only connected ones

                    vector<pair<int,int>>directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

                    while(!q.empty()){
                        auto [r,c] = q.front(); q.pop();

                        for(auto &[dr, dc] : directions){
                            int nr = dr + r;
                            int nc = dc + c;

                            if(nc>=0 && nc<n && nr>=0 && nr<m && grid[nr][nc] == '1' && !visited[nr][nc]){
                                q.push({nr, nc});
                                visited[nr][nc] = true;
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};