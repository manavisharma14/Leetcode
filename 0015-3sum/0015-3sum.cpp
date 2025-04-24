class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>result;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;

            int sum = 0;
            while(j<k){
                sum = nums[i] + nums[j] + nums[k];

                if(sum > 0){
                    k--;
                }
                else if(sum<0){
                    j++;
                }
                else if(sum == 0){
                    result.push_back({nums[i], nums[j], nums[k]});
                    while(j<k && nums[j] == nums[j+1]) j++;
                    while(j<k && nums[k] == nums[k-1]) k--;

                    j++;
                    k--;
                }
            }
        }
        return result;
    }
};