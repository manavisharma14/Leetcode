class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        queue<pair<int,int>>q;

        q.push({sr,sc});
        int originalcolor = image[sr][sc];
        
        if (originalcolor == color) return image;

        image[sr][sc] = color;

        int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            int i = node.first;
            int j = node.second;

            for(int k=0; k<4; k++){
                int dx = i + directions[k][0];
                int dy = j + directions[k][1];

                if(dx>=0 && dx<m && dy>=0 && dy<n && image[dx][dy] == originalcolor){
                    q.push({dx, dy});
                    image[dx][dy] = color;
                }
            }
        }
        return image;
    }
};