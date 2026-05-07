class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p1=0;
        int p2=0;
        string res;

        for(int i=0; p1 < word1.length() || p2 < word2.length(); i++){
            if(p1<word1.length()){ res += word1[p1]; p1++;}
            if(p2<word2.length()){ res += word2[p2]; p2++; }
        }
        return res;
    }
};