class Solution {
public:

    bool func(int index, vector<int>& nums, int target, int n, vector<vector<int>>&dp){
        if(target == 0) return true;
        if(index<0 || target< 0) return false;

        bool nottake = func(index-1, nums, target, n, dp);
        bool take = false;

        if(dp[index][target] != -1) return dp[index][target];

        if(nums[index] <= target){
            take = func(index-1, nums, target-nums[index], n, dp);
        }
        dp[index][target] = take || nottake;
        return dp[index][target];
    }

    bool canPartition(vector<int>& nums) {
        // entire sum = S
        int n = nums.size();
        int totalsum = 0;

        for(int num: nums){
            totalsum+= num;
        }
        if(totalsum%2 != 0) return false;

        int target = totalsum/2;
        vector<vector<int>>dp(n, vector<int>(target+1, -1));

        return func(n-1, nums, target, n, dp);

    }
};