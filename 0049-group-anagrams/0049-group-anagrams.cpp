class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;
        unordered_map<string, vector<string>>mp;

        for(int i=0; i<strs.size(); i++){
            string sorted = strs[i];

            sort(sorted.begin(), sorted.end());
            mp[sorted].push_back(strs[i]);
        }

        for(auto &entry : mp){
            result.push_back(entry.second);
        }
        return result;
    }
};