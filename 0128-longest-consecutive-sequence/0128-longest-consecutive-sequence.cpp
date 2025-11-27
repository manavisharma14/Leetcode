class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
        int maxlen = 0;

        unordered_set<int>s;

        for(int num : nums){
            s.insert(num);
        }

        for(int num : s){
            if(s.find(num-1) == s.end()){
                int val = num;
                int count = 1;
                while(s.find(val+1) != s.end()){
                    count++;
                    val = val+1;
                }
                maxlen = max(maxlen, count);
            }
            
        }
        return maxlen;
    }
};