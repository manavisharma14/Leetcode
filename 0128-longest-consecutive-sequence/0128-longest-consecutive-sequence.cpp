class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>s;
        int maxlen = 0;

        for(int num : nums ){
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