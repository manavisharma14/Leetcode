class Solution {
private:
    bool deleteone(int l, int r, string s){
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

        int left = 0;
        int right = n-1;

        while(left<right){
            if(s[left] == s[right]){
                left++;
                right--;
                continue;
            }

            else if(s[left] != s[right]){
                return deleteone(left+1, right, s) || deleteone(left, right-1, s);
            }
        }
        return true;
    }

};