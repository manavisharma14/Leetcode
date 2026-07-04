class Solution {
private:
    bool skipcheck(int l, int r, string s){
        while(l<r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

public:

    bool validPalindrome(string s){
        int n = s.length();
        
        int l = 0;
        int r = n-1;

        while(l<r){
            if(s[l] != s[r]){
                return skipcheck(l+1, r, s) || skipcheck(l, r-1, s);
            }
            l++;
            r--;
        }
        return true;
    }

};