class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;

        for(int num: nums){
            if(mp.find(num) != mp.end()) return true;
            mp[num] = num;
        }
        return false;
    }
};