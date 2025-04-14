class Solution {
public:

    int func(int idx, int n, vector<int>& nums, vector<int>& dp){
        if(idx == 0) return nums[0];
        if(idx < 0) return 0;

        if(dp[idx] != -1) return dp[idx];
 
        int pick = func(idx-2, n, nums, dp) + nums[idx];
        int nonpick = func(idx-1, n, nums, dp);

        dp[idx] = max(pick, nonpick);
        return dp[idx];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        return func(n-1, n, nums, dp);
    }
};