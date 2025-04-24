class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;  // Stores the frequency of prefix sums
        int sum = 0;  // Current prefix sum
        int count = 0;

        map[0] = 1;  // To handle the case where the subarray sum is exactly `k` from the start

        for (int i = 0; i < n; i++) {
            sum += nums[i];  // Update the running sum

            // If sum == k, we have found a valid subarray from the beginning to the current index
            if (map.find(sum - k) != map.end()) {
                count += map[sum - k];  // Add how many times `sum - k` has occurred before
            }

            // Record the current prefix sum
            map[sum]++;
        }

        return count;
    }
};
