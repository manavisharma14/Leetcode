class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <=1 ){
            return s;
        }

        string lps = "";

        for(int i=1; i<s.length(); i++){
            // consider odd length

            int low = i;
            int high = i;

            while( low >= 0 && high < s.length() && s[low] == s[high]){
                low--;
                high++;
            }



            // indexes can be used to get the string

            string palindrome = s.substr(low+1, high-low-1);

            if(palindrome.length() > lps.length()){
                lps = palindrome;
            }

            // consider even length

            low = i-1;
            high = i;

            while(low >= 0 && high < s.length() && s[low] == s[high]){
                low--;
                high++;
            }


            // using indixes again to find the sub string palindrome

            palindrome = s.substr(low+1, high-low-1);
            if(palindrome.length() > lps.length()){
                lps = palindrome;
            }
        }
        return lps;
    }
};