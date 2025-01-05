class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalsum = 0;

        for(int i=0; i<nums.size(); i++){
            totalsum += nums[i];
        }
        int n = nums.size();
        vector<long long>prefixsum(n+1, 0);
        int count = 0;

        for(int i=0; i<n-1; i++){
            prefixsum[i+1] = prefixsum[i] + nums[i];
            if (prefixsum[i + 1] >= (totalsum - prefixsum[i + 1])) { 
            count++; 
        }
        }
        return count;
    }
};