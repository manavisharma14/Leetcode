class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor_result = 0;
        int n = nums.size();

        // XOR all numbers from 0 to n
        for(int i = 0; i <= n; i++) {
            xor_result ^= i;
        }
        for(int num : nums){
            xor_result ^= num;
        }
        return xor_result;
    }
};