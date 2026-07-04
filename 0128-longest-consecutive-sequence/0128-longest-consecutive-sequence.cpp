class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        int maxcount = 0;

        for(int num : nums){
            s.insert(num);
        }

        for(int num: s){
            if(s.find(num-1) == s.end()){
                int curr = num;
                int count = 1;
                while(s.find(curr+1) != s.end()){
                    count++;
                    curr++;
                }

                maxcount = max(count, maxcount);
            }
        }
        return maxcount;
    }   
};  