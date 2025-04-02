class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        // For each bit position (0 to 31)
        for (int i = 0; i < 32; i++) {
            int bitcount = 0;

            for (int num : nums) {
                if (num & (1 << i)) {
                    bitcount++;
                }
            }

            if(bitcount % 3 == 1){
                result |= (1<<i);
            }
        }

        return result;
    }
};
