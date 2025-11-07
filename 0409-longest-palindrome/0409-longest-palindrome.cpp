class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;

        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        int length = 0;
        bool oddfound = false;
        for(auto &[ch, freq] : mp){
            length += freq/2 *2;
            if(freq%2 == 1) oddfound = true;
        }
        if(oddfound == true) length += 1;
        return length; 
    }
};