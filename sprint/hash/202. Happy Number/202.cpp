#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> uSet{n};
        int newN = 0;
        while (n != 1) {
            newN = 0;
            while (n >= 1) {
                newN += (n % 10) * (n % 10);
                n = n / 10;
            }
            n = newN;
            
            if (uSet.count(n) == 1) {
                return false;
            }
            uSet.insert(n);
        }
        return true;
    }
};