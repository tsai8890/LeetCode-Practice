using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
    /*
        Title: 278. First Bad Version
        Time Complexity: O(log(N))
        Algorithm: 
            1. Binary Search
                        
        Date: 12/06/2021 22:57	
        Time: 0 ms  -- beat 100.00%
        Memory: 5.9 MB  -- beat 65.87%
    */
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        int mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;    
            }
        }
        
        return left;
    }
};