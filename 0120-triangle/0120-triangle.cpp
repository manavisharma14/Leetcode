class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();

        vector<vector<int>>dp(m);

        // initialising dp to match triangle[i].size()

        for(int i=0; i<m; i++){
            dp[i] = vector<int>(triangle[i].size(), 0);
        }

        for(int i=m-1; i>=0; --i){
            for(int j=0; j<triangle[i].size(); j++){
                if(i==m-1) dp[i][j] = triangle[i][j];
                else{
                    int down = dp[i+1][j];
                    int diag = dp[i+1][j+1];
                    dp[i][j] = min(down, diag) + triangle[i][j];
                }
            }
        }
        return dp[0][0];
    }
};