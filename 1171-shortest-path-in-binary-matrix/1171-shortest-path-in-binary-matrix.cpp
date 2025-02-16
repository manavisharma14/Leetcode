class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        if(grid[0][0] == 1|| grid[rows-1][cols-1] == 1){
            return -1;
        }

        int directions[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1}};
        vector<vector<int>> distance(rows, vector<int>(cols, 1e9));

        distance[0][0] = 1;
        pq.push({1,{0,0}});

        while(!pq.empty()){
            int dis = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (row == rows - 1 && col == cols - 1) {
                return dis;
            }

            for(int i=0; i<8; i++){
                int drow = row + directions[i][0];
                int dcol = col + directions[i][1];

                if(drow >=0 && drow < rows && dcol >=0 && dcol < cols && grid[drow][dcol] == 0 && 1 + dis < distance[drow][dcol]){
                    distance[drow][dcol] = 1 + dis;
                    pq.push({1+dis, {drow, dcol}});
                }
            }
        }
        return -1;
    }
};