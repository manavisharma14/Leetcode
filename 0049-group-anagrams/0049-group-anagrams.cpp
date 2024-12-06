class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>anagramMap;

        for(string s: strs){
            string sortedstr = s;
            sort(sortedstr.begin(), sortedstr.end());
            anagramMap[sortedstr].push_back(s);
        }

        vector<vector<string>>result;

        for(auto&pair : anagramMap){
            result.push_back(pair.second);
        }
        return result;
    }
};