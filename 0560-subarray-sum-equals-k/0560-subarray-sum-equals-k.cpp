class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int prefixSum = 0; // Running prefix sum
        unordered_map<int, int> map; // Store prefix sum frequencies

        map[0] = 1; // Base case for subarrays starting at index 0

        for (int num : nums) {
            prefixSum += num; // Update the running prefix sum

            // Check if there exists a prefix sum that makes the current sum equal to k
            if (map.find(prefixSum - k) != map.end()) {
                count += map[prefixSum - k];
            }

            // Update the frequency of the current prefix sum
            map[prefixSum]++;
        }

        return count;
    }
};
