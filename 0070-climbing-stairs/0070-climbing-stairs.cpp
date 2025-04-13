class Solution {
public:

    int climbstairs(int n, vector<int>&dp){
        if(n<=1) return 1;

        if(dp[n] != -1) return dp[n];

        return dp[n] = climbstairs(n-1,dp) + climbstairs(n-2,dp);
    }

    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return climbstairs(n,dp);
    }
};