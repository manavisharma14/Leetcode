class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        int originalColor = image[sr][sc];
        int m = image.size();
        int n = image[0].size();

        vector<vector<bool>>visited(m, vector<bool>(n, false));

        q.push({sr, sc});
        image[sr][sc] = color;
        visited[sr][sc] = true;

        vector<pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            for(auto &[dx, dc] : directions){
                int nx = dx+row;
                int nc = dc+col;

                if(nx>=0 && nx<m && nc>=0 && nc<n && !visited[nx][nc] && image[nx][nc] == originalColor){
                image[nx][nc] = color;
                visited[nx][nc] = true;
                q.push({ nx, nc });
            }
            }
        }
        return image;

    }
};