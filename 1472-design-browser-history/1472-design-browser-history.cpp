class BrowserHistory {
public:
    stack<string>history;
    stack<string>pagesahead;

    BrowserHistory(string homepage) {
        history.push(homepage);
    }
    
    void visit(string url) {
        history.push(url);
        while(!pagesahead.empty()){
            pagesahead.pop();
        }
    }
    
    string back(int steps) {
        while(steps > 0 && history.size() > 1){
            pagesahead.push(history.top());
            history.pop();
            steps--;
        }
        return history.top();
    }
    
    string forward(int steps) {
        while(steps > 0 && !pagesahead.empty()){
            history.push(pagesahead.top());
            pagesahead.pop();
            steps--;
        }
        return history.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */