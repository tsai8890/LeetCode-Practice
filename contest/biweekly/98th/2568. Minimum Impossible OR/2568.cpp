#include <unordered_set>
#include <vector>
using namespace std;

// Misc

class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> dict;
        for (auto num: nums) {
            dict.insert(num);
        }
        
        int x = 1;
        while (true) {
            if (dict.find(x) == dict.end()) {
                return x;
            }
            x *= 2;
        }
        return -1;
    }
};