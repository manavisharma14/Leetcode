class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        vector<int>res;

        for(int num: nums){
            mp[num]++;
        }

        for(auto [num, freq] : mp){
            if(freq > n/3){
                res.push_back(num);
            }
        }
        return res;
    }
};