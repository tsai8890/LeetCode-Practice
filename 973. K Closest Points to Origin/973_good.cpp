#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
    /*
        Title: 973. K Closest Points to Origin
        Time Complexity: 
            1. Average Case: O(n)
            2. Worst Case: O(n^2)

        Algorithm:
            1. Quick Select

        Note:
            1. vector有內建的swap function，比自己寫快很多。
               Usage: vector<int> a, b;
                      a.swap(b);
                
        Date: 12/26/2021 22:04						
        Time: 128 ms  -- beat 94.92%
        Memory: 51.8 MB  -- beat 80.17%
    */
public:
    int dist(vector<int>& A) {
        return A[0]*A[0] + A[1]*A[1];
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        srand(time(0));
        quick_select(points, k);
        
        vector<vector<int>> result;
        for (int i = 0; i < k; i ++) {
            result.push_back(points[i]);
        }
        return result;
    }
    
    void quick_select(vector<vector<int>>& points, int k) {
        int left = 0, right = points.size() - 1;
        int pivot = -1;
        
        while (true) {
            pivot = lomuto_partition(points, left, right);

            if (pivot+1 < k) {
                left = pivot + 1;
            
            } else if (pivot+1 > k) {
                right = pivot - 1;
            
            } else {
                break;
            }
        }
    }
    
    int lomuto_partition(vector<vector<int>>& points, int left, int right) {
        int pivot = left + rand() % (right-left+1);
        points[pivot].swap(points[right]);
        int pivot_dist = dist(points[right]);
        
        int i = left, j = left;
        for (; j <= right; j ++) {
            if (dist(points[j]) <= pivot_dist) {
                points[i].swap(points[j]);
                i += 1;
            }
        }
        return i - 1;
    }
};