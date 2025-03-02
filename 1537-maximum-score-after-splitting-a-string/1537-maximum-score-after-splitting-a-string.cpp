class Solution {
public:
    int maxScore(string s) {
        int count1=0;
        int left0=0, right1=0, maxscore=0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '1'){
                count1++;
            }
        }
        right1 = count1;
        for(int i=0; i<s.length()-1; i++){
            if(s[i] == '0'){
                left0++;
            }
            else if(s[i] == '1'){
                right1--;
            }
            maxscore = max(maxscore, left0+right1);
        }
        return maxscore;
    }
};