class Solution {
public:


    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==0) return 0;
        if(n==1) return nums[0];


        int prev2 = nums[0];
        int prev = max(nums[0], nums[1]);

        for(int i=2; i<n; i++){
            int pick = prev2 + nums[i];
            int nonpick = prev;

            int curi = max(pick, nonpick);
            prev2 = prev;
            prev = curi;
        }


        return prev;
    }
};