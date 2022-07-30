#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> calculator;
        for (string token: tokens) {
            if (token.length() > 1 || isdigit(token[0])) {
                calculator.push(stoi(token));
            }
            else {
                int op2 = calculator.top();
                calculator.pop();
                int op1 = calculator.top();
                calculator.pop();

                switch (token[0]) {
                    case '+':
                        calculator.push(op1 + op2);
                        break;

                    case '-':
                        calculator.push(op1 - op2);
                        break;

                    case '*':
                        calculator.push(op1 * op2);
                        break;

                    case '/':
                        calculator.push(op1 / op2);
                        break;
                }
            }
        }
        return calculator.top();
    }
};