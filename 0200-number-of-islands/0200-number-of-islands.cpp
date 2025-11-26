class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m, vector<int>(n,0));

        
        int islands = 0;

        for(int i=0 ;i<m ; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    islands++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    visited[i][j] = 1;

                    vector<pair<int,int>>directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
                    while(!q.empty()){
                        auto [r,c] = q.front();
                        q.pop();

                        for(auto &[dr,dc] : directions){
                            int nr = r+dr;
                            int nc = c+dc;

                            if(nr>=0 && nr<m && nc>=0 && nc<n && !visited[nr][nc] && grid[nr][nc] == '1'){
                                q.push({nr, nc});
                                visited[nr][nc] = 1;
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};