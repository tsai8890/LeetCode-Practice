#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        
        int n = path.length();
        stack<string> pathStack;
        string segment = "";

        for (int i = 0; i < n; i ++) {
            if (path[i] != '/') {
                segment += path[i];
            }
            else {
                if (segment.empty()) {}
                
                else if (segment == ".") {}
                
                else if (segment == "..") {
                    if (!pathStack.empty()) {
                        pathStack.pop();
                    }
                }
                else {
                    pathStack.push(segment);
                }
                segment.clear();
            }
        }
        
        string res = "";
        while (!pathStack.empty()) {
            res = "/" + pathStack.top() + res;
            pathStack.pop();
        }
        return (!res.empty()) ? res : "/";
    }
};