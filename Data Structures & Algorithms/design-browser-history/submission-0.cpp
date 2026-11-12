class BrowserHistory {
private:
    vector<string> history;
    int cur, n;

public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        cur = 0;
        n = 1;
    }
    
    void visit(string url) {
        cur++;
        
        if (cur == history.size()) {
            history.push_back(url);
            n++;
        } else {
            history[cur] = url;
            n = cur + 1;
        }
    }
    
    string back(int steps) {
        cur = max(0, cur - steps);
        return history[cur];
    }
    
    string forward(int steps) {
        cur = min(n - 1, cur + steps);
        return history[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */