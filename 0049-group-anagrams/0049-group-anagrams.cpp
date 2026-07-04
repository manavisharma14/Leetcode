class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        vector<vector<string>>result;

        for(string str: strs){
            string sortedstr = str;
            sort(sortedstr.begin(), sortedstr.end());
            mp[sortedstr].push_back(str);
        }

        for(auto& it: mp){
            result.push_back(it.second);
        }

        return result;
    }
};