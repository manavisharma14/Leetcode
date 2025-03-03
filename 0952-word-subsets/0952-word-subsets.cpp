class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> maxfreq;
        vector<string>ans;


        for(const string& word: words2){
            unordered_map<char,int>freq;
            for(char c: word){
                freq[c]++;
            }
            for(auto& [c,count] : freq){
                maxfreq[c] = max(maxfreq[c], count);
            }
        }

        vector<string>result;

        for(const string& word: words1){
            unordered_map<char,int>freq;
            for(char c: word){
                freq[c]++;
            }

            bool isuniversal = true;
            for(auto& [c, requiredfreq] : maxfreq){
                if(freq[c] < requiredfreq){
                    isuniversal = false;
                }
            }
            if(isuniversal){
                ans.push_back(word);
            }
        }

        return ans;


    }
};