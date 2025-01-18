class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0, xor2 = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        
        for(int num: nums1){
            xor1 ^= num;
        }

        for(int num: nums2){
            xor2 ^= num;
        }

        int result = 0;

        if(n1%2 == 1){
            result ^= xor2;
        }

        if(n2%2 == 1){
            result ^= xor1;
        }
        return result;
    }
};
