#include <vector>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector <int> arr;
        while (n >= 1) {
            arr.push_back(n % 2);
            n = n / 2;
        }
        
        int prev = arr[0];
        for (int i = 1; i < arr.size(); i ++) {
            if (arr[i] == prev)
                return false;
            prev = arr[i];
        }
        return true;
    }
};