class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int maxsum = nums[0];

        for(int i=1; i<n; i++){
            if(nums[i-1] < nums[i]){
                sum += nums[i];
            }
            else{
            maxsum = max(sum, maxsum);
            sum = nums[i];
            }
        }
        return max(maxsum, sum);
    }
};