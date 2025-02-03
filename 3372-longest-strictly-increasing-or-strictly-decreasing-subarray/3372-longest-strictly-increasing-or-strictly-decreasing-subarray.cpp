class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int inc = 1, dec = 1;
        int ans=0;
        if(n==1) return 1;

        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]) inc++, dec=1;
            else if(nums[i-1]>nums[i]) inc=1, dec++;
            else inc=dec=1;
            ans = max({inc, dec, ans});
        }
        return ans;
    }
};