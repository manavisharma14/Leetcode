class Solution {
public:


    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        
        if(n==0 || n==1) return n;

        dp[0] = dp[1] = 1;

        for(int i=2; i<=n ;i++){
            dp[i] = dp[i-2] + dp[i-1];
        }

        return dp[n];
    }
};