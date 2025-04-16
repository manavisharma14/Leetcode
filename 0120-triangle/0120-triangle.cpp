class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();

        vector<vector<int>>dp;
        for(int i=0; i<m; i++){
            dp.push_back(vector<int>(triangle[i].size(), -1));
        }

        for(int j=0; j<n; j++){
            dp[m-1][j] = triangle[m-1][j];
        }

        for(int i=m-2; i>=0; i--){
            for(int j=0; j<triangle[i].size(); j++){
                int up = dp[i+1][j] ;
                int diag = dp[i+1][j+1];
                dp[i][j] = triangle[i][j] + min(up, diag);
            }
        }
        
        return dp[0][0];
    }
};