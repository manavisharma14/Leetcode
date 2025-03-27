class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int count = 0;
        long long current_sum = 0, xor_sum = 0;

        int n = nums.size();
        int right = 0;
        int left=0;

        while(right<n){
            current_sum += nums[right];
            xor_sum ^= nums[right];

            if(current_sum != xor_sum){
                current_sum -= nums[left];
                xor_sum ^= nums[left];
                left++;
            }

            count = max(count, right-left+1);
            right++;
        }
        return count;
    }
};