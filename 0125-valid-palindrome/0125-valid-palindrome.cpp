class Solution {
public:
    bool isPalindrome(string s) {
        string ans;

        for(char c: s){
            if(isalnum(c)){
                ans+=tolower(c);
            }
        }
        int n = ans.size();
        for(int i=0; i<n/2; i++){
            if(ans[i] != ans[n-1-i]){
                return false;
            }
        }
        return true;
    }
};