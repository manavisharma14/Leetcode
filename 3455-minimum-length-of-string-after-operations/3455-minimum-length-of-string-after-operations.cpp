class Solution {
public:
    int minimumLength(string s) {
        vector<int> charFreq(26,0);
        int totallength = 0;

        for(char c : s){
            charFreq[c-'a']++;
        }

        for(int freq : charFreq){
            if(freq == 0) continue;
            if(freq % 2 == 0){
                totallength += 2;
            } else {
                totallength += 1;
            }
        }
        return totallength;
    }
};