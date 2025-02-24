class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>>distance(m, vector<int>(n,0));
        vector<vector<int>>visited(m, vector<int>(n,0));

        queue<pair<pair<int,int>,int>>q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j}, 0});
                    distance[i][j] = 0;
                    visited[i][j] = 1;

                }
            }
        }

        int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int newr = row + directions[i][0];
                int newc = col + directions[i][1];

                if(newr>=0 && newr<m && newc>=0 && newc<n && !visited[newr][newc]){
                    visited[newr][newc] = 1;
                    distance[newr][newc] = dis + 1;
                    q.push({{newr, newc}, dis+1});
                }
            }
        } 

    return distance;

    }
};