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
        while(steps >0 && current > 0){
            current = current-1;
            steps--;
        }
        return history[current];

        if(steps > history.size()) return history[0];
    }
    
    string forward(int steps) {
        while(steps > 0 && current < history.size()-1){
            current = current+1;
            steps--;
        }

        return history[current];

        if(steps > history.size()){
            return history[history.size()-1];
        }
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */