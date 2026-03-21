class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        size_t minlen = INT_MAX;
        string ans;

        for(int i=0; i<n; i++){
            minlen = min(minlen, strs[i].length());
        }

        for(int j=0; j<minlen; j++){
            for(int i=1; i<n; i++){
                if(strs[0][j] != strs[i][j]){
                    return ans;
                }
            }
            ans += strs[0][j];
        }
        return ans;
    }
};