class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        vector<vector<string>>ans;

        for(int i=0; i<strs.size(); i++){
            string word = strs[i];
            sort(word.begin(), word.end());

            mp[word].push_back(strs[i]);
        }
        for(auto &p: mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};