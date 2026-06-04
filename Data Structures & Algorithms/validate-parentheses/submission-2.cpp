class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int n = s.size();
        char t;
        for(char c : s){
            if(!stk.empty()){
                t = stk.top();
                if(c == ')') {
                    if(stk.top() == '(') stk.pop();
                    else return false;
                }
                else if(c == ']') {
                    if(stk.top() == '[') stk.pop();
                    else return false;
                }
                else if(c == '}') {
                    if(stk.top() == '{') stk.pop();
                    else return false;
                }
                else stk.push(c);
            }
            else stk.push(c);
        }
        return stk.empty();
    }
};
