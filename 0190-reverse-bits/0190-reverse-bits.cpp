class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;

        for(int i=0; i<32; i++){
            if((n & (1<<i))){
                ans = ans | (1<<(31-i));
            }
        }
        return ans;
    }
};