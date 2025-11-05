class Solution {
public:
    bool isValid(string s) {
        std::stack<char>stk;

        for(int i=0; i<s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stk.push(s[i]);
            }
            else if( !stk.empty() && ((s[i] == '}' && stk.top() == '{') || 
                (s[i] == ']' && stk.top() == '[') ||
                (s[i] == ')' && stk.top() == '('))){
                stk.pop();
            } else{ 
                return false;
            }
            
        }
        return stk.empty();
    }
};