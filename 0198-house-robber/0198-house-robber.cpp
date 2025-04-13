class Solution {
public:

    int func(int n, vector<int>&dp, vector<int>& nums){
        if(n == 0) return nums[0];
        if(n == 1) return max(nums[0], nums[1]);

        if(dp[n] != -1) return dp[n];

        int pick = nums[n] + func(n-2, dp, nums);
        int nonpick = func(n-1, dp, nums);

        return dp[n] = max(pick, nonpick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n+1, -1);

        return func(n-1,dp, nums);
    }
};