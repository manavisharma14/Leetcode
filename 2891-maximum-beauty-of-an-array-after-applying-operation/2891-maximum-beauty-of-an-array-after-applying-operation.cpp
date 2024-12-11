class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
     sort(nums.begin(), nums.end());

    int n = nums.size();
    int left = 0, maxBeauty = 0;

    // Sliding window to count valid range
    for (int right = 0; right < n; ++right) {
        // Check if the range is valid
        while (nums[right] - nums[left] > 2 * k) {
            ++left;
        }
        // Update maximum beauty
        maxBeauty = max(maxBeauty, right - left + 1);
    }
    
    return maxBeauty;
    }
};