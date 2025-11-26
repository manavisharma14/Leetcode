class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>mp;

        for(int i=0 ;i<s.length(); i++){
            mp[s[i]]++;
        }

        for(int i=0; i<t.length(); i++){
            if(mp.find(t[i]) != mp.end()){
                mp[t[i]]--;
            } else {
                return false;
            }
        }

        for( auto &[ch, freq] : mp){
            if(freq < 0 || freq > 0){
                return false;
            }
        }
        return true;
    }
};