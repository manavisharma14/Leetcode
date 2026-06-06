class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0=0, count1=0, count2=0;

        for(int x: nums){
            if(x==0) count0++;
            else if(x==1) count1++;
            else if(x==2) count2++;
        }

        for(int i=0; i<count0; i++){
            nums[i] = 0;
        }
        for(int i=count0; i<count0+count1; i++){
            nums[i] = 1;
        }
        for(int i=count0+count1; i<nums.size(); i++){
            nums[i] = 2;
        }
    }
};