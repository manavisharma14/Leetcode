// 151. Reverse Words in a String
class Solution {
public:
    string reverseWords(string s) {

    int n = s.length();
    int temp;
    int i; 
    int start = 0;
    int end ; 

    
    for(int i=0; i<n/2 ;i++){
        temp = s[i];
        s[i] = s[n-1 - i];
        s[n-1-i] = temp;
    } 

    for(int i=0; i<n ;i++){
        if(s[i] == ' ' ){
            end = i-1;
            while(start<end){
                temp = s[start];
                s[start] = s[end];
                s[end] = temp;
                start++;
                end--;
            }
            start = i+1;
        }
    }
    //reverse the last word

    end = n-1;
    while(start<end){
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }



    return s;
    

    
    }
};