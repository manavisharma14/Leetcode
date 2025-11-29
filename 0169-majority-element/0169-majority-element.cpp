class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int size = nums.size();

        for(int num: nums){
            mp[num]++;
        }

        for(auto [n, freq] : mp){
            if(freq > size/2){
                return n;
            }
        }
        return -1;
    }
};