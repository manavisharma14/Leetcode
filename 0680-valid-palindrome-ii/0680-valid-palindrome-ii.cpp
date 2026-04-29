class Solution {
public:

    bool check(int l, int r, string s){
        while(l<r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.length();
        int left = 0;
        int right = n-1;

        while(left<right){
            if(tolower(s[left]) != tolower(s[right])){
                if(check(left+1, right, s)) return true;
                else if(check(left, right-1, s)) return true;
                else return false;
            }
            left++;
            right--;
        }
        return true;   
    }

};