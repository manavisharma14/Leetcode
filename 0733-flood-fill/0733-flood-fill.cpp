class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        vector<vector<bool>>visited(m, vector<bool>(n, false));

        std::queue<pair<int,int>>q;
        q.push({sr,sc});
        int originalcolor = image[sr][sc];

        image[sr][sc] = color;

        while(!q.empty()){
            auto [r,c] = q.front(); q.pop();

            vector<pair<int,int>>directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
            for(auto [dr,dc] : directions){
                int nr = r + dr;
                int nc = c + dc;

                if(nr>=0 && nr<m && nc>=0 && nc<n && image[nr][nc] == originalcolor && !visited[nr][nc]){
                    image[nr][nc] = color;
                    visited[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};