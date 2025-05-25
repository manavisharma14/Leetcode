class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for(int num: nums){
            sum += num;
        }
        if(sum%2 != 0) return false;

        int target = sum/2;
        vector<vector<int>>dp(n, vector<int>(target+1, false));

        for(int i=0; i<n; i++) dp[i][0] = true;

        for(int i=1; i<n; i++){
            for(int j=1; j<=target; j++){
                bool take = false;
                if(j>=nums[i]){
                    take = dp[i-1][j-nums[i]];
                }
                bool nottake = dp[i-1][j];
                dp[i][j] = take || nottake;
            }  
        }
        return dp[n-1][target];
    }
};