class Solution {
public:
    int maxScore(string s) {
        int n=s.length();

        int sum0 = 0, sum1 = 0;
        int ans=0;

        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                sum1++;
            }
        }

        for(int i=0; i<n-1; i++){
            if(s[i] == '0') sum0++;
            else if(s[i] == '1') sum1--;

            ans = max(ans, sum0+sum1);
        }
        return ans;
    }
};