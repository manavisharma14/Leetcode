class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size()/2;

        unordered_map<int,int>freq;

        for(int num: nums){
            freq[num]++;
        }

        for(auto i: freq){
            if(i.second>n){
                return i.first;
            }
        }
        return 0;
    }
};