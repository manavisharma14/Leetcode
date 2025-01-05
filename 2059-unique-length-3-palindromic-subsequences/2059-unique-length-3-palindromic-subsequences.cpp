class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        int ans = 0;
        int n = s.length();
        unordered_map<char,pair<int,int>>map;
        
        for(int i=0; i<s.length(); i++){
            if(map.find(s[i]) == map.end()){
                map[s[i]].first = map[s[i]].second = i;
            }

            else{
                map[s[i]].second = i;
            }
        }


        for(auto &[ch, positions] : map){
            int left = positions.first;
            int right = positions.second;

            if(right-left <= 1) continue;

            unordered_set<char> uniquechars;

            for(int i=left+1; i<right; i++){
                uniquechars.insert(s[i]);
            }

            ans += uniquechars.size();
        }
        return ans;
    }
};