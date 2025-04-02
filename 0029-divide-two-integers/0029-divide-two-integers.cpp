class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        if(dividend == divisor)
            return 1;

        long long ans = 0;

        bool isPositive = (dividend >= 0) == (divisor >= 0);

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);



        while(n >= d){
            int count = 0;
            while(n >= (d << (count+1))){
                if ((d << (count + 1)) < 0 || (count + 1) >= 31) break;
                count++;
            }
            ans += 1<<count;
            n = n - (d * (1<<count));
        }

    return isPositive ? ans : -ans;
    }
};