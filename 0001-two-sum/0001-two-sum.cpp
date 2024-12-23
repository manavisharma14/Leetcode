class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mapp;
        int n = nums.size();

        // build hash table

        for(int i=0; i<n; i++){
            mapp[nums[i]] = i;
        }

        for(int i=0; i<n; i++){
            int complement = target - nums[i];
            if(mapp.count(complement) && mapp[complement] != i){
                return {i, mapp[complement]};
            }
        }
        return {};
    }
};