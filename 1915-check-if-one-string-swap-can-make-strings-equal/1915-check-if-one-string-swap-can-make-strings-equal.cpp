class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        vector<int>difference;

        if(s1 == s2) {
            return true;
        }

        if(s1.length() != s2.length()){
            return false;
        }
        
        for(int i=0; i<n; i++){
            if(s1[i]!=s2[i]){
                difference.push_back(i);
            }
        }

        if(difference.size() != 2){
            return false;
        }

        int i = difference[0];
        int j = difference[1];
        return s1[i] == s2[j] && s1[j] == s2[i];

        
    }
};