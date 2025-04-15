class Solution {
public:

    int func(vector<int>& nums, int start, int end){
        int len = end - start + 1;

        if(len == 1) return nums[start];

        int prev2 = nums[start];
        int prev = max(nums[start], nums[start+1]);

        for(int i=2; i<len; i++){

            int curi = max(prev2 + nums[start+i], prev);
            prev2 = prev;
            prev = curi;
        }

        return prev;
    }


    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==0) return 0;

        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);



        int ans1 = func(nums, 0, n-2);
        int ans2 = func(nums, 1, n-1);

        return max(ans1, ans2);

        
        
    }
};