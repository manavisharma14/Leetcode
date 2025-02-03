class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>visited(m , vector<int>(n,0));

        for(int i=0; i<m ; i++){
            for(int j=0; j<n; j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(grid[i][j] == 1){
                        q.push({i,j});
                        visited[i][j] = 1;
                    }
                }
            }
        }

        int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int dx = row + directions[i][0];
                int dy = col + directions[i][1];

                if(dx>=0 && dx<m && dy>=0 && dy<n && !visited[dx][dy] && grid[dx][dy] == 1){
                    visited[dx][dy] = 1;
                    q.push({dx,dy});
                }
            }
        }
        
        int count = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    count++;
                }
            }
        }
        return count;
    }
};