class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        int maxlen = 0;

        for(int x: nums){
            s.insert(x);
        }

        // for(int i=0; i<nums.size(); i++){
        //     if(s.find(nums[i]-1) == s.end()){
        //         int curr = nums[i];
        //         int len = 1;
        //         while(s.find(curr+1) != s.end()){
        //             len++;
        //             curr++;
        //         }
        //         maxlen = max(len, maxlen);
        //     }
        // }
    
        for(int x: s){
            if(s.find(x-1) == s.end()){
                int curr = x;
                int len = 1;
                while(s.find(curr+1) != s.end()){
                    curr++;
                    len++;
                }
                maxlen = max(len, maxlen);
            }
        }
        return maxlen;
    }   
};