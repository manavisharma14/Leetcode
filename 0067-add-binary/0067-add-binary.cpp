class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.length();
        int n2 = b.length();
        int carry = 0;
        int i=n1-1, j=n2-1;
        string result = "";

        while(i>=0 && j>=0){
            int sum = (a[i]-'0' + b[j]-'0' + carry);
            result += (sum % 2) + '0';
            carry = sum/2;
            i--; 
            j--;
        }

        // remaining digits of a
        while(i>=0){
            int sum = (a[i] - '0') + carry;
            result += (sum % 2) + '0';
            carry = sum/2;
            i--;
        }

        while(j>=0){
            int sum = (b[j] - '0') + carry;
            result += (sum % 2) + '0';
            carry = sum/2;
            j--;
        }

        if(carry){
            result += '1';
        }


        reverse(result.begin(), result.end());
        return result;


    }
};