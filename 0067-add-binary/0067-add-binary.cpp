class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.length();
        int n2 = b.length();
        string result = "";

        int i=n1-1;
        int j=n2-1;
        int carry = 0;

        while(i>=0 && j>=0){
            int sum = (a[i]-'0' + b[j]-'0' + carry) ;
            result += sum%2 + '0';
            carry = sum/2;
            i--;
            j--;
        }

        while(i>=0){
            int sum = (a[i]-'0' + carry) ;
            result += sum%2 + '0';
            carry = sum/2;
            i--;
        }

        while(j>=0){
            int sum = (b[j]-'0' + carry) ;
            result += sum%2 + '0';
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