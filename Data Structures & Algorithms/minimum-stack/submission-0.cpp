class MinStack {

private:
    stack<int> s;
    stack<int> extra;

public:
    MinStack() {}
    
    void push(int val) {
        s.push(val);
        int top = extra.empty() ? val : extra.top();
        val = min(val, top);
        extra.push(val);
    }
    
    void pop() {
        if(!s.empty()) s.pop();
        if(!extra.empty()) extra.pop();
    }
    
    int top() {
        if(!s.empty()) return s.top();
    }
    
    int getMin() {
        return extra.top();
    }
};
