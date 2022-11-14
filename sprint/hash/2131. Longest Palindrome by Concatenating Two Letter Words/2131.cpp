#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> hashT;
        int len = 0;
        int double_count = 0;
        
        for (auto& w: words) {
            string wr = w;
            reverse(wr.begin(), wr.end());
            
            if (hashT.find(wr) != hashT.end()) {
                len += 4;
                hashT[wr] --;
                if (hashT[wr] == 0) {
                    hashT.erase(hashT.find(wr));
                }
                if (wr[0] == wr[1]) {
                    double_count --;
                }
            }
            else {
                if (hashT.find(w) != hashT.end()) {
                    hashT[w] ++;
                }
                else {
                    hashT[w] = 1;
                }
                
                if (w[0] == w[1]) {
                    double_count ++;
                }
            }
        }
        
        if (double_count > 0) {
            len += 2;
        }
        return len;
    }
};