class Solution {
public:

    int func(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        if(i==0 && j==0) return grid[0][0];

        if(i<0 || j<0) return INT_MAX;

        if(dp[i][j] != -1) return dp[i][j];

        int up = func(grid, i-1, j, dp) ;
        int left = func(grid, i, j-1, dp) ;

        return dp[i][j] = grid[i][j] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m, vector<int>(n,-1));

        int ans = func(grid,m-1, n-1, dp);
        return ans;
    }
};