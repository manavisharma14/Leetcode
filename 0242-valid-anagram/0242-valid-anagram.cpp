class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.length();
        int n = t.length();

        unordered_map<char,int>freq;

        if(m != n){
            return false;
        }

        for(char c : s){
            freq[c]++;
        }

        for(char c : t){
            freq[c]--;

            if(freq[c] < 0){
                return false;
            }
        }

        for(auto it: freq){
            if(it.second != 0){
                return false;
            }
        }

        return true;
    }
};