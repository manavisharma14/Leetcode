class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int length = 0;
        int n = s.length();
        unordered_map<char,int>mp;

        int right = 0;
        int left = 0;

        while(right < n){
            int cur = s[right];
            if(mp.find(cur) != mp.end() && mp[cur] >= left){
                left = mp[cur] + 1;
            }

            mp[cur] = right;
            maxlen = max(maxlen, right-left+1);
            right++;
        }
        return maxlen;
    }
};