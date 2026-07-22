class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        int p1=0, p2=0;
        string res;

        while(p1<n1 || p2<n2){
            if(p1<n1) res += word1[p1++];
            if(p2<n2) res += word2[p2++];
        }
        return res;
    }
};