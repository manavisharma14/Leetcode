class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size()/2;

        unordered_map<int,int>freq;

        for(int num: nums){
            freq[num]++;
            if(freq[num] > n) return num; 
        }
        return -1;
    }
};