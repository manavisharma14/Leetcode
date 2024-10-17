//345. reverse vowels of a string

class Solution {
public:
    string reverseVowels(string s) {
        char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        int size = s.size();
        char temp;

        int left=0;
        int right=size-1;

        auto isVowel = [&](char c){
            for(int i=0; i<10; i++){
                if(c == vowels[i])
                    return true;
            }
            return false;
        } ;

        // 2 pointer approach

        while(left<right){

            while(left<right && !isVowel(s[left])){
                left++;
            }
            while(left<right && !isVowel(s[right])){
                right--;
            }

            if(left<right){
                
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;

                left ++;
                right --;
            }
        }
        return s;
    }
};