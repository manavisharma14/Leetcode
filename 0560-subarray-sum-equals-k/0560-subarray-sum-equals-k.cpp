class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int prefixsum = 0;
        unordered_map<int,int>mp;
        mp[0] = 1;


        
        for(int x: nums){
            prefixsum += x;

            if(mp.find(prefixsum-k) != mp.end()){
                count += mp[prefixsum - k];
            }

            mp[prefixsum]++;

        }
        return count;
    }
};