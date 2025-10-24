class Solution {
public:
    bool isValid(string s) {
        std::stack<char>mystack;

        if(s.length() == 0) return true;

        for(int i=0; i<s.length(); i++){
            if(s[i] == '{' || s[i] == '(' || s[i] == '['){
                mystack.push(s[i]);
            }


            if(s[i] == '}' || s[i] == ')' || s[i] == ']'){
                if(mystack.empty()) return false;
                if(s[i] == '}') {
                    if(mystack.top() != '{' ) return false;
                } else if(s[i] == ']') {
                    if(mystack.top() != '[' ) return false;
                } else if(s[i] == ')') {
                    if(mystack.top() != '(' ) return false;
                }
            }
            
            if(!mystack.empty()){
                if(s[i] == '}'){
                if(mystack.top() == '{') mystack.pop();
            } else if(s[i] == ']'){
                if(mystack.top() == '[') mystack.pop();
            } else if(s[i] == ')'){
                if(mystack.top() == '(') mystack.pop();
            } 
            }
        }
        return mystack.empty();
    }
};