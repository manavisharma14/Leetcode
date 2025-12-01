class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int>stk;
        for(int i=0; i<operations.size(); i++){
            if(operations[i] == "C"){
            stk.pop();
        } else if(operations[i] == "D"){
            if(!stk.empty()){
                stk.push(2*(stk.top()));
            }
        } else if(operations[i] == "+"){
            int first = stk.top();
            stk.pop();
            int second = stk.top();
            stk.pop();

            stk.push(second);
            stk.push(first);
            stk.push(first+second);
        } else {
            stk.push(stoi(operations[i]));
        }
        } 

        int sum = 0;
        while(!stk.empty()){
            sum += stk.top(); stk.pop();
        }
        return sum;
    }
};