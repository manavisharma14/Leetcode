class Solution {
public:
    bool check(string &s, int l, int r){
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
        int count = 0;

        while(left < right){
            if(s[left] == s[right]){
                left++;
                right--;
            }
            else if(s[left] != s[right]){
                return check(s, left+1, right) ||
                check(s, left, right-1);
            }
        }
        return true;
    }
};