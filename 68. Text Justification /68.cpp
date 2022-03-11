#include <vector>
#include <string>
using namespace std;

class Solution {
    /*
        Title: 68. Text Justification
        Time Complexity:
            1. O(total length of the result + words.size())

        Algorithm:
            1. None

        Note:
            1. 這題是hard應該是因為做法比較繁雜，但是並不需要
               演算法才能解這道題。

        Date: 12/18/2021 13:56							
        Time: 0ms  -- beat 100.00%
        Memory: 7.4 MB  -- beat 51.87%
    */
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int cur_count = words[0].length();
        int line_start = 0;

        for (int i = 1; i < words.size(); i ++) {
            if (cur_count + words[i].length() + 1 <= maxWidth) {
                cur_count += words[i].length() + 1;
            
            } else {
                string line = words[line_start];
                
                if (i == line_start + 1) {
                    while (line.length() < maxWidth) {
                        line += " ";
                    }
                } else {
                    int nIntervals = i - line_start - 1; 
                    cur_count -= nIntervals;
                    int remain_spaces = maxWidth - cur_count;

                    int threshold = remain_spaces % nIntervals;
                    int n_spaces = remain_spaces / nIntervals;
                    string temp = " ";

                    for (int j = line_start + 1; j < i; j ++) {
                        for (int k = 0; k < n_spaces; k ++) 
                            line += " ";
                        if (j-(line_start+1) < threshold) 
                            line += " ";
                        line += words[j];
                    }
                }
                
                result.push_back(line);
                line_start = i;
                cur_count = words[i].length();
            }
        }

        string line = words[line_start];
        for (int i = line_start + 1; i < words.size(); i ++) {
            line += " " + words[i];
        }
        while (line.length() < maxWidth) {
            line += " ";
        }
        result.push_back(line);
        
        return result;
    }
};