class MinStack {
private:
    stack<long> stk1;
    long mn;
public:
    MinStack() {}
    
    void push(int val) {
        if(stk1.empty()){
            stk1.push(0);
            mn = val;
        }
        else{
            stk1.push(val-mn);
            if(mn > val) mn = val;
        }
    }
    
    void pop() {
        if(stk1.empty()) return;
        long pop = stk1.top();
        stk1.pop();
        if(pop < 0) mn = mn - pop;
    }
    
    int top() {
        long top = stk1.top();
        return (top > 0) ? (top + mn) : (int)mn;
    }
    
    int getMin() {
        return (int)mn;
    }
};
