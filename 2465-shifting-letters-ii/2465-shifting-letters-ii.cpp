class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {

        int n = s.length();
        vector<int>prefixsum(n+1, 0);
        for(auto& shift: shifts){
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            if (direction == 0) { // Left shift
                prefixsum[start] -= 1;
                prefixsum[end + 1] += 1;
            } 
            else { // Right shift
                prefixsum[start] += 1;
                prefixsum[end + 1] -= 1;
            }
        }

        int shiftvalue=0;
        for(int i=0; i<n; i++){
            shiftvalue += prefixsum[i];
            int newchar = ((s[i] - 'a') + shiftvalue)%26;
            if(newchar < 0) newchar += 26;
            s[i] = 'a' + newchar;
        }

        return s;
    }
};