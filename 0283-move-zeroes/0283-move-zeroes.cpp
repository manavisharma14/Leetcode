class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>res(n);
        int j=0;

        for(int i=0; i<n; i++){
            if(nums[i] == 0) continue;

            if(nums[i] != 0){
                nums[j++] = nums[i];
            }
        
        }
        while(j<n){
            nums[j++] = 0;
        }

    }
};