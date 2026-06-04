class Solution {
public:
    bool isAnagram(string s, string t) {
        int l1 = s.length();
        int l2 = t.length();

        unordered_map<int,int>mp;

        for(int i=0; i<l1; i++){
            mp[s[i]] += 1;
        }

        for(int i=0; i<l2; i++){
            if(mp.find(t[i]) != mp.end()){
                mp[t[i]]--;
            } else return false;
        }

        for(auto &p : mp){
            if(p.second != 0) return false;
        }
        return true;
    }
};