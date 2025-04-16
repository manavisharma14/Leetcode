class Solution {
public:

    int func(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        // base case : last row n-1th row
        int m = triangle.size();
        if(i==m-1) return triangle[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int down = func(i+1, j, triangle, dp);
        int diag = func(i+1, j+1, triangle, dp);

        return dp[i][j] = triangle[i][j] + min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[0].size();

        vector<vector<int>>dp;
        for(int i=0; i<m; i++){
            dp.push_back(vector<int>(triangle[i].size(), -1));
        }
        
        int ans = func(0,0, triangle, dp);
        
        return ans;
    }
};