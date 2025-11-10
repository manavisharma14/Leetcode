class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<bool>>visited(m, vector<bool>(n, false));

        vector<vector<int>>result(m, vector<int>(n,0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
        }
        
        int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!q.empty()){
            auto [r,c] = q.front(); q.pop();

            for(auto [dr, dc] : directions){
                int nrow = dr + r;
                int ncol = dc + c;

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol] && mat[nrow][ncol] != 0){
                    result[nrow][ncol] = result[r][c] + 1;
                    visited[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
            }

            
        }
        return result;
    }
};