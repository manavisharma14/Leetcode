class Solution {
public:
    string addBinary(string a, string b) {
        int sum = 0;
        int carry = 0;
        string res= "";

        int i = a.length()-1;
        int j = b.length()-1;

        while(i>=0 || j>=0 || carry){
            int bitA = (i>=0)? a[i] -'0' : 0;
            int bitB = (j>=0)? b[j]-'0' : 0;

            sum = bitA ^ bitB ^ carry;
            
            carry = (bitA & bitB) | (bitA & carry) | (bitB & carry);

            res = char(sum + '0') + res;
            i--;
            j--;
        }

        
        return res;
      
    }
};