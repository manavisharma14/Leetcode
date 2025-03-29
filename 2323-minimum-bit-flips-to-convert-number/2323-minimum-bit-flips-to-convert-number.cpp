class Solution {
public:
    int countsetbits(int n){
        int count = 0;
        while(n>0){
            count += n&1;
            n = n>>1;
        }
        return count;
    }

    int minBitFlips(int start, int goal) {
        int diff = start^goal;

        return countsetbits(diff);
    }
};