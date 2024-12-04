class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i=0, j=0;
        int m = str1.length();
        int n = str2.length();

        while(i<m and j<n){
            if(str1[i]-'a' == str2[j]-'a' || (str1[i]-'a'+1)%26 == str2[j]-'a'){
                j++;
            }

            if(j==n){
                return true;
            }
            i++;
        }
        return false;
    }
};
