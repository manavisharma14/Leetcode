class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>map;

        // build the hash table
        for(int i=0; i<nums.size(); i++){
            map[nums[i]] = i;
        }

        for(int i=0; i<nums.size(); i++){
            int complement = target - nums[i];
            if(map.count(complement) && map[complement] != i){
                return {i, map[complement]};
            }
        }
        return {};
    }
};