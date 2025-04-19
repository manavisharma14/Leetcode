class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<long long, long long>freq;
        long long pairs = 0;
long long res = 0;

        int n = nums.size();

        long long left = 0;

        for (long long right = 0; right < n; ++right) {
            // Add current element to the window
            pairs += freq[nums[right]];
            freq[nums[right]]++;

            // Shrink the window until pairs < k
            while (pairs >= k) {
                // All subarrays starting from left to right are valid
                res += (n - right);

                freq[nums[left]]--;
                pairs -= freq[nums[left]];
                left++;
            }
        }
        return res;
    }
};