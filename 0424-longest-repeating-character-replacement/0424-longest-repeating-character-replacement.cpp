class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0;
        int maxFreq = 0;
        int maxWindow = 0;
        int n = s.length();

        for(int right=0; right<n; right++){
            freq[s[right] - 'A']++;

            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            int windowLength = right-left+1;

            if(windowLength - maxFreq > k){
                freq[s[left] - 'A']--;
                left++;
            }

            windowLength = right - left + 1;
            maxWindow = max(maxWindow, windowLength);
        }
        return maxWindow;
    }
};