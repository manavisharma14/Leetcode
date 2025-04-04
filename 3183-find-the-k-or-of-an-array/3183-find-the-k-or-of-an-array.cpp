class Solution {
public:

    int findKOr(vector<int>& nums, int k) {
        int result = 0;
        for(int i=0; i<32; i++){
            int bitcount = 0;
            for(int num: nums){
                if(num & (1<<i)){
                    bitcount++;
                }
            }
            if(bitcount>=k){
                result |= (1<<i);
            }
        }
        return result;
    }
};