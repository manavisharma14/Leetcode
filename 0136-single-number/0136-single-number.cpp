class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sumxor = 0;

        for(int i=0; i<nums.size(); i++){
            sumxor ^= nums[i];
        }
        return sumxor;
    }
};