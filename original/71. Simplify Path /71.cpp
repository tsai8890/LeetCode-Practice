#include <iostream>
#include <string>
#include <deque>

using namespace std;

/*
    Title: 71. Simplify Path
    Time Complexity: O(N)
    Algorithm: 
        1. Stack
    
    Date: 10/04/2021 21:50		
    Time: 3 ms  -- beat 92.80%
    Memory: 9.5 MB  -- beat 48.47%
*/

class Solution {
public:
    string simplifyPath(string path) {
        path += "/";

        deque<string> deq;
        string segment = "";
        
        int i = 0;
        while (i < path.length()) {
            if (path[i] != '/')
                segment += path[i];
            
            else {
                if (segment != "") {
                    if (segment == ".") {
                        //pass
                    } else if (segment == "..") {
                        if (!deq.empty()) 
                            deq.pop_back();
                    } else {
                        deq.push_back(segment);
                    }
                    segment = "";
                }
            }
            i += 1;
        }
        
        string can_path = "";
        while (!deq.empty()) {
            string added = deq.front();
            deq.pop_front();
            can_path += "/" + added;
        }
        
        if (can_path == "")
            can_path = "/";
        
        return can_path;
    }
};