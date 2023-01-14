#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five = 0, ten = 0, twenty = 0;
        for (int i = 0; i < n; i ++) {
            if (bills[i] == 5) {
                five ++;
            }
            else if (bills[i] == 10) {
                if (five == 0) return false;
                five --;
                ten ++;
            }
            else {
                if (five >= 1 && ten >= 1) {
                    five --;
                    ten --;
                    twenty ++;
                }
                else if (five >= 3) {
                    five -= 3;
                    twenty ++;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};