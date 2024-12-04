class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>duplicates;

        for(int i=0; i<nums.size(); i++){
            if(duplicates.find(nums[i]) != duplicates.end()){
                return true;
            }
            duplicates[nums[i]] = 1;
        }
        return false;
    }
};