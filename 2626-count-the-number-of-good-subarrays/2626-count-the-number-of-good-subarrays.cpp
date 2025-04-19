class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<long long, long long> freq;

        long long equal_pairs = 0;
        long long goodsubarrays = 0;

        long long left = 0;
        long long right = 0;

        int n = nums.size();

        for(right=0; right<n; right++){
            equal_pairs += freq[nums[right]];
            freq[nums[right]]++;

            while(equal_pairs >= k){
                goodsubarrays += (n-right);
                freq[nums[left]]--;
                equal_pairs -= freq[nums[left]];
                left++;
            }
        }
        return goodsubarrays;
    }
};