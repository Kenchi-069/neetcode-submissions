class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (auto &t : tokens) {
            if ((t == "+") || (t == "-") || (t == "*") || (t == "/")) {
                int n1 = stk.top();
                stk.pop();
                int n2 = stk.top();
                stk.pop();

                if (t == "+") stk.push(n2 + n1);
                else if (t == "-") stk.push(n2 - n1);
                else if (t == "*") stk.push(n2 * n1);
                else stk.push(n2 / n1);
            } else {
                stk.push(stoi(t));
            }
        }

        return stk.top();
    }
};