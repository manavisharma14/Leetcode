class Solution {
public:

    int func(vector<int>& nums, int n, int idx, int start, vector<int>& dp){
        if(idx<start) return 0;
        if(idx == start) return nums[start];

        if(dp[idx] != -1) return dp[idx];

        int pick = func(nums, n, idx-2, start, dp) + nums[idx];
        int nonpick = func(nums, n, idx-1, start, dp);

        dp[idx] = max(pick, nonpick);
        return dp[idx];

    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n==0) return 0;
        if(n==1) return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        
        int ans1 = func(nums, n, n-2, 0, dp1);
        int ans2 = func(nums, n, n-1, 1, dp2);

        return max(ans1, ans2);
    }
};