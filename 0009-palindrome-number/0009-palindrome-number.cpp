class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }

        int ans = 0;
        int original = x;

        while(x!=0){
            int digit = x%10;

            if((ans > INT_MAX / 10) || (ans < INT_MIN /10)){
                return false;
            }
            ans = ans*10 + digit;
            x = x/10;
        }
        return original == ans;
    }
};