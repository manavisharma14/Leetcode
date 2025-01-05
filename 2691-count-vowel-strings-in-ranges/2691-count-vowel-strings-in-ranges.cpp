class Solution {
public:

    bool isVowel(char c){
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        int n = words.size();
        vector<int>prefixsum(n+1, 0);

        for(int i=0; i<words.size(); i++){
            const string &word = words[i];

            if (isVowel(word[0]) && isVowel(word[word.length() - 1])) {
                prefixsum[i+1] = prefixsum[i] + 1;
            } 
            else {
                prefixsum[i+1] = prefixsum[i];
            }
        }


        vector<int>result;

        for(const auto& query: queries){
            int li = query[0];
            int ri = query[1];

            result.push_back(prefixsum[ri+1] - prefixsum[li]);
        }
        return result;
    }
};