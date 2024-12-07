class Solution {
public:
    // Helper function to check if a given penalty can be achieved within maxOperations
    bool canDivide(const vector<int>& nums, int maxPenalty, int maxOperations) {
        int operations = 0;
        for (int num : nums) {
            if (num > maxPenalty) {
                operations += (num - 1) / maxPenalty;
            }
            if (operations > maxOperations) {
                return false;
            }
        }
        return true;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1; // Minimum possible penalty
        int right = *max_element(nums.begin(), nums.end()); // Maximum possible penalty
        int result = right; // Variable to store the minimum penalty

        // Binary search to find the minimum penalty
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDivide(nums, mid, maxOperations)) {
                result = mid; // Update result with the current minimum penalty
                right = mid - 1; // Try for a smaller penalty
            } else {
                left = mid + 1; // Try for a larger penalty
            }
        }

        return result;
    }
};
