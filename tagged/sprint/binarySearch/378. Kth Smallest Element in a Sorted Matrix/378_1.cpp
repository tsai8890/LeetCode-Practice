#include <vector>
using namespace std;

#define vt vector

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0], r = matrix.back().back();
        while (l < r) {
            int mid = (l+1==r && r < 0) ? l : (l+r)/2;
            if (count(matrix, mid) < k) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        } 
        return l;
    }

    int count(vt<vt<int>>& matrix, int threshold) {
        int lCol = 0, rRow = matrix.size()-1;
        int total = 0;
        while (lCol < matrix.size() && rRow >= 0) {
            if (matrix[rRow][lCol] <= threshold) {
                total += rRow+1;
                lCol ++;
            }
            else {
                rRow --;
            }
        } 
        return total;   
    }
};