class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mp;
        int maxlen = 0;
        int len = 0;

        int n = s.length();
        int left = 0;
        int right = 0;

        while(right<n){
            char c = s[right];
            if(mp.find(c) != mp.end() && mp[c] >= left){
                left = mp[c]+1;
            }

            mp[c] = right;
            maxlen = max(maxlen, right-left+1);
            right++;
        }
        return maxlen;
    }
};