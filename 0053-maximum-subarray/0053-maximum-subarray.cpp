 class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int sum = 0;         

        for(int num: nums) {
            if(sum < 0) {
                sum = 0;  
            }

            sum += num;  
            
            maxi = max(maxi, sum);  
        }

        return maxi;  
    }
};
