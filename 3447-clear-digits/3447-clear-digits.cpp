class Solution {
public:
    string clearDigits(string s) {
        stack<int>st;

        for(int i=0; i<s.length(); i++){
            if(isalpha(s[i])){
                st.push(s[i]);
            }
            else if(isdigit(s[i])){
                st.pop();
            }
        }

        string result;
        
        while(!st.empty()){
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};