class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_map<char, pair<int,int>>map;
        int ans =0;

        for(int i=0; i<n; i++){
            if(map.find(s[i]) == map.end()){
                map[s[i]].first = i;
            }
            map[s[i]].second = i;
        }

        for(auto& [ch, positions] : map){
            int left = positions.first;
            int right = positions.second;


            if(right-left <=1) continue;

            unordered_set<char>uniquechars;
            for(int i=left+1; i<right; i++){
                uniquechars.insert(s[i]);
            }
            ans+= uniquechars.size();
        }
        return ans;
    }
};