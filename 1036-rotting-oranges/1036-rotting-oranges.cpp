class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int time = 0;

        queue<pair<pair<int,int>,int>>q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                }
            }
        }

        int dir[4][2] = {{1 ,0 } , {-1 , 0} , {0 , 1} , {0 , -1}};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int x = q.front().second;
            time = max(time, x);
            q.pop();

            for(int i=0; i<4; i++){
                
                int nr = r + dir[i][0], nc = c + dir[i][1];

                if(nr >= 0 && nr < m && nc>=0 && nc < n){
                    if(grid[nr][nc] == 1){
                        q.push({{nr,nc}, x+1});
                        grid[nr][nc] = 2;
                    }
                    }
                }
            }

            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(grid[i][j] == 1){
                        return -1;
                    }
                }
            }
        
        return time;
    }
};