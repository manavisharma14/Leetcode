class Solution {
public:
    int roblinear(vector<int>& nums, int start, int end){
        if(start>end) return 0;
        int prev = nums[start];
        int prev2 = 0;

        for(int i=start+1; i<=end; i++){
            int curr = max(prev, prev2+nums[i]);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        return max(roblinear(nums,0,n-2), roblinear(nums,1,n-1));
    }
};