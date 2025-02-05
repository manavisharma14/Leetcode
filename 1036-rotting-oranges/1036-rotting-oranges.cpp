class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int time=0;
        int freshoranges=0;

        vector<vector<int>>visited(m, vector<int>(n,0));
        queue<pair<int,int>>q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    visited[i][j] = 1;
                } else if(grid[i][j] == 1){
                    freshoranges++;
                }
            }
        }

        int directions[4][2] = {{1,0},{-1,0}, {0,1}, {0,-1}};
        while(!q.empty() && freshoranges>0){
            int size = q.size();
            bool rotten = false;


            for(int i=0; i<size; i++){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
           

            for(int i=0; i<4; i++){
                int dx = row + directions[i][0];
                int dy = col + directions[i][1];

                if(dx>=0 && dx<m && dy>=0 && dy<n && grid[dx][dy] == 1 && !visited[dx][dy]){
                    grid[dx][dy] = 2;
                    q.push({dx,dy});
                    visited[dx][dy] = 1;
                    freshoranges--;
                    rotten = true;
                }
            }
            }
        if (rotten) time++;
        }
        return freshoranges == 0? time : -1;
    }
};
