class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int m = grid.size();
        int n = grid[0].size();


        int time = 0;
        int fresh = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        vector<pair<int,int>>directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()){
            int size = q.size();
            bool rottenThisMinute = false;

            for(int i=0; i<size; i++){
                auto [r, c] = q.front();
                q.pop();
            

                for(auto [dr,dc] : directions){

                    int nr = r+dr;
                    int nc = c+dc;

                    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                        rottenThisMinute = true;
                    }
                }
            }
            if(rottenThisMinute) time++;
        }
        
        return (fresh == 0)? time : -1;
    }
};