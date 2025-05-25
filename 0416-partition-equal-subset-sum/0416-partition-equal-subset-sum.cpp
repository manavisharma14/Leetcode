class Solution {
public:

    bool func(vector<int>& nums, int index, int target, vector<vector<int>>& dp){

        if(target == 0) return true;
        if (index < 0 || target < 0) return false;

        if(dp[index][target] != -1) return dp[index][target];

        bool nottake = func(nums, index-1, target, dp);

        bool take = false;
        if(target>=nums[index]){
            take = func(nums, index-1, target-nums[index], dp);
        }
        return dp[index][target] = take || nottake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for(int num: nums){
            sum += num;
        }
        if(sum%2 != 0) return false;

        int target = sum/2;
        vector<vector<int>>dp(n, vector<int>(target+1, -1));

        return func(nums, n-1, target, dp);

    }
};