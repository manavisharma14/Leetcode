class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p1 = 0;
        int p2 = 0;
        int n = 0;
        string result;

        int n1 = word1.length();
        int n2 = word2.length();

        while(p1<n1 || p2<n2){
            if(p1<n1) result += word1[p1++];
            if(p2<n2) result += word2[p2++];
        }
        return result;
    }
};