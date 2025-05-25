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
        vector<int>prev(target+1, false);

        prev[0] = true;

        for(int i=0; i<n; i++){
            vector<int>curr(target+1, false);
            for(int j=1; j<=target; j++){
                bool take = false;
                if(j>=nums[i]){
                    take = prev[j-nums[i]];
                }
                bool nottake = prev[j];
                curr[j] = take || nottake;
            }  
            prev = curr;
        }
        return prev[target];
    }
};