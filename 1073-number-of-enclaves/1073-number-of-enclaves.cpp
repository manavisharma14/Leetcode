class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m, vector<int>(n,0));
        queue<pair<int,int>>q;

        for(int i=0; i<m; i++){
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

                if(dx>=0 && dx<m && dy>=0 && dy<n && grid[dx][dy] == 1 && !visited[dx][dy]){
                    q.push({dx,dy});
                    visited[dx][dy] = 1;
                }
            }
        }

        int count=0; 

        for(int i=0 ;i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};