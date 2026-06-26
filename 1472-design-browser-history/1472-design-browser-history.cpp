class BrowserHistory {
public:
    stack<string> historyuptocurrent;
    stack<string> pagesahead;

    BrowserHistory(string homepage) {
        historyuptocurrent.push(homepage);
    }
    
    void visit(string url) {
        historyuptocurrent.push(url);
        while(!pagesahead.empty()){
            pagesahead.pop();
        }
    }
    
    string back(int steps) {
        while(steps > 0 && historyuptocurrent.size() > 1){
            pagesahead.push(historyuptocurrent.top());
            historyuptocurrent.pop();
            steps--;
        }
        return historyuptocurrent.top();
    }
    
    string forward(int steps) {
        while(steps > 0 && !pagesahead.empty()){
            historyuptocurrent.push(pagesahead.top());
            pagesahead.pop();
            steps--;
        }
        return historyuptocurrent.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */