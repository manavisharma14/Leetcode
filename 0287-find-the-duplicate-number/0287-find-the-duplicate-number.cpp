class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>freq;

        for(int num : nums){
            freq[num]++;
        }

        for(auto &[num, occ] : freq){
            if(occ >= 2){
                return num;
            }
        }
        return -1;
    }
};