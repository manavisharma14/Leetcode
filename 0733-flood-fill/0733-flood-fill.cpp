class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        queue<pair<int,int>>q;
        int oldcolor = image[sr][sc];

        vector<vector<int>>visited(m, vector<int>(n,0));

        image[sr][sc] = color;

        q.push({sr,sc});
        visited[sr][sc] = 1;

        int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()){
            auto node = q.front(); q.pop();
            int row = node.first;
            int col = node.second;

            for(int i=0; i<4; i++){
                int newr = row + directions[i][0];
                int newc = col + directions[i][1];

                if(newr >=0 && newr<m && newc>=0 && newc<n && image[newr][newc] == oldcolor && !visited[newr][newc]){
                    image[newr][newc] = color;
                    visited[newr][newc] = 1;
                    q.push({newr, newc});
                }
            }
        }

        return image;

    }
};