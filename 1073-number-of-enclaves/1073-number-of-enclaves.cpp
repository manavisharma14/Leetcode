class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        // cal no of enclosed land cells

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>visited(m, vector<int>(n,0));
        queue<pair<int,int>>q;
        
        // travserse the first and last row
        for(int j=0; j<n; j++){
            if(grid[0][j] == 1) q.push({0,j});
            visited[0][j] = 1;
            if(grid[m-1][j] == 1) q.push({m-1, j});
            visited[m-1][j] = 1;
        }

        // traverse the first and last col
        for(int i=0; i<m; i++){
            if(grid[i][0] == 1) q.push({i,0});
            visited[i][0] = 1;
            if(grid[i][n-1] == 1) q.push({i,n-1});
            visited[i][n-1] = 1;
        }

        int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int newr = row + directions[i][0];
                int newc = col + directions[i][1];

                if(newr>=0 && newr<m && newc>=0 && newc<n && grid[newr][newc] == 1 && !visited[newr][newc]){
                    visited[newr][newc] = 1;
                    q.push({newr, newc});
                }
            }

        }
        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};