#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> calculator;
        for (string token: tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int op2 = calculator.top();
                calculator.pop();
                int op1 = calculator.top();
                calculator.pop();

                if (token == "+") calculator.push(op1 + op2);
                if (token == "-") calculator.push(op1 - op2);
                if (token == "*") calculator.push(op1 * op2);
                if (token == "/") calculator.push(op1 / op2);
            }
            else {
                calculator.push(stoi(token));
            }
        }
        return calculator.top();
    }
};