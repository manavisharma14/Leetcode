class Solution {
public:

    int countSetBits(int n) {
    int count = 0;

    while(n>0){
        if(n&1){
            count++;
        }
        n = n>>1;
    }
    return count;
    }

    

    

    int minimizeXor(int num1, int num2) {
        
        int setbits1 = countSetBits(num1);
        int setbits2 = countSetBits(num2);

        if(setbits1 == setbits2){
            return num1;
        }
        
        int result = 0;
        if(setbits2 > setbits1){
            int diff = setbits2 - setbits1;
            result = num1;

            for(int i=0; i<32 && diff > 0; i++){
                if((result & (1 << i)) == 0){
                    result |= (1 << i);
                    diff--;
                }
            }


        }
        else{
            // reduce setbits in 1
            int diff = setbits1 - setbits2;
            result = num1;

            for(int i=0; i<32 && diff > 0; i++){
                if (result & (1 << i)) { // If bit is 1, make it 0
                    result &= ~(1 << i);
                    diff--;
                }
            }
        }
        return result;
    }
};