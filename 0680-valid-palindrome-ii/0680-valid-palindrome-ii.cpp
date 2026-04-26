class Solution {
public:
    
    bool check(int l, int r, string s){
        int n = s.length();
        while(l<r){
            if(s[r] != s[l]) return false;
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.length();
        int left = 0;
        int right = n-1;

        while(left < right){
            int skip = 0;
            if(s[left] != s[right]){
                if(check(left+1, right, s) || check(left, right-1, s)) return true;
                else return false;
            }
            left++;
            right--;
        }
        return true;
    }
};