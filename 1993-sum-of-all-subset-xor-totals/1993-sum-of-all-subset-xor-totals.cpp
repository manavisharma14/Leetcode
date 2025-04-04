class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int totalsum = 0;

        int subsets = 1<<n;

        for(int num=0; num<subsets; num++){
            int subsetxor = 0;
            for(int i=0; i<n; i++){
                if( num&(1<<i)){
                    subsetxor ^= nums[i];
                }
            }
            totalsum += subsetxor;   
        }
        return totalsum;
    }
};