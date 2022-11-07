#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n;
        
        int i = 1;
        while (i < n) {
            while (i < n && ratings[i] == ratings[i-1]) {
                i ++;
            }
            
            int peak = 0;
            while (i < n && ratings[i] > ratings[i-1]) {
                peak ++;
                candy += peak;
                i ++;
            }
            
            int valley = 0;
            while (i < n && ratings[i] < ratings[i-1]) {
                valley ++;
                candy += valley;
                i ++;
            }
            
            candy -= min(peak, valley);
        }
        return candy;
    }
};