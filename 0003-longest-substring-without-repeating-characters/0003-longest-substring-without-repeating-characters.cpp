class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxlen = 0;
        unordered_map<int,int>mp;

        int left = 0;
        int right = 0;

        while(right<n){
            
            char c = s[right];
            if(mp.find(c) != mp.end() && mp[c] >= left){
                left = mp[c] + 1;
            }
            mp[s[right]] = right;
            maxlen = max(maxlen, right-left+1);
            right++;
        }
        return maxlen;
    }
};