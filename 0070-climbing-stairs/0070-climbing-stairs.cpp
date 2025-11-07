class Solution {
public:
    int func(vector<int>&dp, int n){
        if(n==0 || n==1) return dp[n];

        if(dp[n] != -1) return dp[n];
        dp[n] = func(dp, n-1) + func(dp, n-2);
        return dp[n];
    }

    int climbStairs(int n) {
        vector<int>dp(n+1,-1);

        dp[0] = 1;
        dp[1] = 1;

        return func(dp, n);
    }
};