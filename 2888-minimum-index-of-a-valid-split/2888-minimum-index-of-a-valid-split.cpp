class Solution {
public:
    int minimumIndex(vector<int>& nums) {

        unordered_map<int,int>freq;
        for(int num : nums){
            freq[num]++;
        }

        int n = nums.size();
        int dominant = -1;

        for(auto &[num, count]: freq){
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

            int leftsize = i+1;
            int rightsize = n-leftsize;
            int rightcount = totalcount - leftcount;

            if(leftcount*2 > leftsize && rightcount*2 > rightsize){
                return i;
            }
        }

    return -1;
    }
};