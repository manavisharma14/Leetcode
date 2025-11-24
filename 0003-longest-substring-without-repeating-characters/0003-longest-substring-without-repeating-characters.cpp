class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int maxlen = 0;
        int left = 0;
        int right = 0;
        int n = s.length();

        while(right < n){
            int cur = s[right];
            if(mp.find(cur) != mp.end() && mp[cur] >= left){
                left = mp[cur] + 1;
            }
            maxlen = max(maxlen, right-left+1);
            mp[cur] = right;
            right++;
        }
        return maxlen;
    }
};