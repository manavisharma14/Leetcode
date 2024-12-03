class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> num_maps;
        for(int i=0; i<nums.size(); i++){
            int complement = target - nums[i];
        
                if(num_maps.find(complement) != num_maps.end()){
                
                return {num_maps[complement], i};
                }
                num_maps[nums[i]] = i;
            
        }
        return {};
    }
};