class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0, xor2 = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        
        // Compute XOR of nums1
        for (int num : nums1) {
            xor1 ^= num;
        }

        // Compute XOR of nums2
        for (int num : nums2) {
            xor2 ^= num;
        }

        // Calculate result based on the lengths of nums1 and nums2
        int result = 0;
        if (n1 % 2 == 1) result ^= xor2; // Include nums2 if nums1 length is odd
        if (n2 % 2 == 1) result ^= xor1; // Include nums1 if nums2 length is odd

        return result;
    }
};
