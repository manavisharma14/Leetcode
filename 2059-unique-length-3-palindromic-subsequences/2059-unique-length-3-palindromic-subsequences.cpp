class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        unordered_map<char, pair<int,int>>map;
        int n = s.length();
        int ans=0;

        for(int i=0; i<n; i++){
            if(map.find(s[i]) == map.end()){
                map[s[i]].first = map[s[i]].second = i;
            }
            else{
                map[s[i]].second = i;
            }
        }


        

        for(auto& [ch, positions]: map){
            int left = positions.first;
            int right = positions.second;

            if(right-left <= 1) continue;

            unordered_set<char>uniquechar;
            for(int i=left+1; i<right; i++){
                uniquechar.insert(s[i]);
            }

            ans+=uniquechar.size();
        }
        return ans;
    }
};