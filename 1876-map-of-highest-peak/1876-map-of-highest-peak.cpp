class Solution {
public:

    
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        int rows = isWater.size();
        int cols = isWater[0].size();

        vector<vector<int>>grid(rows, vector<int>(cols, -1));

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(isWater[i][j] == 1){
                    grid[i][j] = 0;
                }
            }
        }

        int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        queue<pair<int,int>>q;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int newr = row + directions[i][0];
                int newc = col + directions[i][1];

                if(newr>=0 && newr<rows && newc>=0 && newc<cols && grid[newr][newc] == -1){
                    grid[newr][newc] = grid[row][col] + 1;
                    q.push({newr, newc});
                }
            }
        }

        
return grid;
    }
};