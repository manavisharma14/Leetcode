class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i=0; i<s.length(); i++){
        // for odd
        count += countPalindromesFromCenter(s, i,i);
        count += countPalindromesFromCenter(s, i, i+1);
        }
        return count;
    }

private: 
    int countPalindromesFromCenter(const string& s, int low, int high){
        int count = 0;

        while(low>=0 and high<s.length() and s[low] == s[high]){
            count++;
            low--;
            high++;
        }
        return count;
    }
};