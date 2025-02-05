class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        vector<vector<int>>visited(m, vector<int>(n,0));

        queue<pair<int,int>>q;
        int originalcolor = image[sr][sc];
        image[sr][sc] = color;
        q.push({sr, sc});
        visited[sr][sc] = 1;

        int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int dx = row + directions[i][0];
                int dy = col + directions[i][1];

                if(dx>=0 && dx<m && dy>=0 && dy<n && image[dx][dy] == originalcolor && !visited[dx][dy]){
                    image[dx][dy] = color;
                    q.push({dx,dy});
                    visited[dx][dy] = 1;
                }
            }

        }
        return image;
    }
};