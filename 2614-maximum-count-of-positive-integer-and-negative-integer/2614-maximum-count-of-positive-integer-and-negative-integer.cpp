class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int ncount=0, pcount=0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0){
                ncount++;
            }
            if(nums[i] > 0){
                pcount++;
            }
        }
        return max(pcount, ncount);
    }
};