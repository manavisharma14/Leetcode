class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        vector<vector<int>>dist(rows, vector<int>(cols, 1e9));
        dist[0][0] = 0;

        pq.push({0, {0,0}});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == rows-1 && col == cols-1) return diff;


            for(int i=0; i<4; i++){
                int newr = row + directions[i][0];
                int newc = col + directions[i][1];

                if(newr>=0 && newr<rows && newc>=0 && newc<cols){
                    int neweffort = max(abs(heights[newr][newc] - heights[row][col]), diff);
                    if(neweffort < dist[newr][newc]){
                        dist[newr][newc] = neweffort;
                        pq.push({neweffort, {newr, newc}});
                    }
                }
            }
        }

        return 0;
    }
};