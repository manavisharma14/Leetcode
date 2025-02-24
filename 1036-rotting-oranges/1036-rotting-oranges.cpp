class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;

        vector<vector<int>>visited(m, vector<int>(n,0));

        int time=0, freshoranges=0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    visited[i][j] = 1;
                }
                if(grid[i][j] == 1){
                    freshoranges++;
                }
            }
        }



        int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty() && freshoranges>0){
            int size = q.size();
            time++;

            for(int i=0; i<size; i++){
                auto node = q.front();
            int row = node.first;
            int col = node.second;
            q.pop();

            for(int i=0; i<4; i++){
                int newr = row + directions[i][0];
                int newc = col + directions[i][1];

                if(newr>=0 && newr<m && newc>=0 && newc<n && grid[newr][newc] == 1 && !visited[newr][newc]){
                    visited[newr][newc] = 1;
                    grid[newr][newc] = 2;
                    freshoranges--;
                    q.push({newr, newc});
                }
            }
            }
        }
        return freshoranges == 0? time: -1;
        
    }
};
