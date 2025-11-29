class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minprelen = INT_MAX;
        string res;

        for(int i=0; i<strs.size(); i++){
            minprelen = min(minprelen, (int)strs[i].size());
        }

        for(int j=0; j<minprelen; j++){
            int c = strs[0][j];
            bool match = true;
            for(int i=1; i<strs.size(); i++){
                if(c != strs[i][j]){
                    match = false;
                }
            }

            if(match){
                res+=c;
            } else break;
        }
        return res;
    }
};