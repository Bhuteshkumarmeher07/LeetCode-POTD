class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto token : tokens) {
            if (token[0] == '+') {
                int a = stk.top();  stk.pop();
                int b = stk.top();  stk.pop();
                stk.push(a+b);
            } else if (token.length() == 1 and token[0] == '-') {
                int a = stk.top();  stk.pop();
                int b = stk.top();  stk.pop();
                stk.push(b-a);
            } else if (token[0] == '*') {
                int a = stk.top();  stk.pop();
                int b = stk.top();  stk.pop();
                stk.push(a*b);
            } else if (token[0] == '/') {
                int a = stk.top();  stk.pop();
                int b = stk.top();  stk.pop();
                stk.push(b/a);
            } else {
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }
};
