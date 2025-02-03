class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>>distance(m, vector<int>(n,0));
        vector<vector<int>>visited(m, vector<int>(n,0));

        queue<pair<pair<int,int>,int>>q;

        for(int i=0 ;i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({{i , j} , 0});
                    distance[i][j] = 0;
                    visited[i][j] = 1;
                }
            }
        }
        
        int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()){
            auto row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            distance[row][col] = steps;

            for(int i=0; i<4; i++){
                int dx = row + directions[i][0];
                int dy = col + directions[i][1];

                if(dx>=0 && dx<m && dy>=0 && dy<n && !visited[dx][dy]){
                    visited[dx][dy] = 1;
                    q.push({{dx, dy}, steps+1});
                }
            }
        }
        return distance;    

    }
};