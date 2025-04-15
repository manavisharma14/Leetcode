class Solution {
public:

    int func(int idx, int n, vector<int>& nums, vector<int>& dp){
        if(idx>n) return 0;

        //pick

        if(dp[idx] != -1) return dp[idx];

        int pick = func(idx+2, n, nums, dp) + nums[idx];
        int nonpick = func(idx+1, n, nums, dp);

        return dp[idx] = max(pick, nonpick);

    }


    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==0) return 0;

        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);

        vector<int>dp1(n, -1);
        vector<int>dp2(n,-1);


        // ans1 0 to n-2
        int ans1 = func(0, n-2, nums, dp1);
        // ans2 1 to n-1
        int ans2 = func(1, n-1, nums, dp2);

        return max(ans1, ans2);
        
        
    }
};