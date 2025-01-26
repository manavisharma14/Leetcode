class Solution {
public:

    
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size();
        int cols = isWater[0].size();

        vector<vector<int>>grid(rows, vector<int>(cols, -1));

        for(int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                if(isWater[i][j] == 1){
                    grid[i][j] = 0;
                }
            }
        }

        queue<pair<int,int>>q;

        for(int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                if(grid[i][j] == 0){
                q.push({i,j});
            }
        }
        }

        int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();

            for(auto [dx, dy] : directions){
                int nx = x + dx;
                int ny = y + dy;

                if(nx >= 0 && nx < rows && ny >=0 && ny < cols && grid[nx][ny] == -1){
                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
return grid;
    }
};