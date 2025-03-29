class Solution {
public:
    int minimumIndex(vector<int>& nums) {

        unordered_map<int,int>freq;

        int dominant = -1;

        for(int num : nums){
            freq[num]++;
        }

        int n = nums.size();

        for(auto &[num, count] : freq){
            if(count*2 > n){
                dominant = num;
                break;
            }
        }


        int leftcount = 0;
        int totalcount = freq[dominant];

        for(int i=0; i<n-1; i++){
            if(nums[i] == dominant){
                leftcount++;
            }

            int rightcount = totalcount - leftcount;
            int leftsize = i+1;
            int rightsize = n - leftsize;

            if(leftcount*2 > leftsize && rightcount*2 > rightsize){
                return i;
            }
        }
        return -1;
    }
};