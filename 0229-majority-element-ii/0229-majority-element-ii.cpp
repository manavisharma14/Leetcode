class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size()/3;
        vector<int>result;

        unordered_map<int,int>freq;

        for(int num: nums){
            freq[num]++;
        }

        for(auto i: freq){
            if(i.second>n){
                result.push_back(i.first);
            }
        }
        return result;
    }
};