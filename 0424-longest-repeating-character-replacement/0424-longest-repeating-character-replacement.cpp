class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int n = s.length();
        unordered_map<int,int>mp;
        int maxlen = 0;
        int maxfreq = 0;

        for(int right=0; right<n; right++){
            mp[s[right] - 'A']++;
            maxfreq = max(maxfreq, mp[s[right] - 'A']);
            while((right-left+1) - maxfreq > k){
                mp[s[left] - 'A']--;
                left++;
            }
            maxlen = max(maxlen, right-left+1);
        }
        return maxlen;
    }
};