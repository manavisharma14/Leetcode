class BrowserHistory {
public:
    vector<string>history;
    int current = 0;

    BrowserHistory(string homepage) {
        history.push_back(homepage);
    }
    
    void visit(string url) {
        history.resize(current+1);
        history.push_back(url);
        current++;
    }
    
    string back(int steps) {
        while(steps > 0 && current > 0 ){
            current--;
            steps--;
        }
        return history[current];
    }
    
    string forward(int steps) {
        while(steps > 0 && current < history.size()-1){
            current++;
            steps--;
        }
        return history[current];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */