class Solution {
public:

    int climbStairs(int n) {


        int prev2 = 1;
        int prev = 1;
        int curi = 0;

        for(int i=2; i<=n; i++){
            curi = prev2 + prev;
            prev2 = prev;
            prev = curi;
            
        }
        return prev;
    }
};