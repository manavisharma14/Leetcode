class Solution {
public:

    
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        vector<int> prefixCount(words.size() + 1, 0);

        auto isVowelString = [](const string& word) {

            char first = word.front(), last = word.back();
            return (first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u') &&
                   (last == 'a' || last == 'e' || last == 'i' || last == 'o' || last == 'u');
        };
        

        for(int i=0; i<words.size(); i++){
            prefixCount[i+1] = prefixCount[i] + (isVowelString(words[i])?1:0);
        }

        vector<int>ans;
        for(auto& query: queries){
            int left = query[0];
            int right = query[1];

            ans.push_back(prefixCount[right+1] - prefixCount[left]);
        }
    return ans;
        
    }
};