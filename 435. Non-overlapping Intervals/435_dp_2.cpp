#include <algorithm>
#include <vector>
using namespace std;

/*
    Title: 435. Non-overlapping Intervals
    Time Complexity: O(n^2) 
    Space Complexity: O(n) - extra space

    Algorithm: 
        1. Dynamic Programming (bottom-up)
        
    Note:
        1.  這題 brutal force 的解法需要 O(2^n) - time 來找出
            所有可能的 subset ，一定會超時

            其實把 intervals 排序後，這題就是典型的 bottom-up DP 題目，
            和 longest increasing sequence 解法一模一樣。
            
            排序方式可以按照 interval[0] (begin) 或是 interval[1] (end)，
            兩種作法都差不多，這篇的做法是按照 ”“”interval[1] (end)“”“ 來排序 intervals

        2.  Dynamic Programming (Bottom-Up):
            dp[i]:  以 intervals[i] 為結尾的最長 non-overlapping intervals 的長度

            DP Transition
                dp[i] = 1 + max(dp[j] if intervals[j][1] <= intervals[i][0])
                        , for j in [0, i-1] 

        3.  Total Time Complexity = O(n^2)
            Total Space Complexity = O(n)

            因為這題 n ~= O(10^5)，所以這種 O(n^2) 的作法還是會超時，
            之後會有另一篇使用 greedy 的解法，時間複雜到可以到 O(nlogn)

    Date: 06/25/2022 21:09																    			
    Time: Time Limit Exceeded
    Memory: Time Limit Exceeded
*/

class Solution {
public:
    static bool cmp_by_end(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp_by_end);
        
        vector<int> dp(n, 0);
        dp[n-1] = 1;
        int max_len = 1;
        for (int i = n-2; i >= 0; i --) {
            int max_tail = 0;
            for (int j = i+1; j < n; j ++) {
                if (intervals[i][1] <= intervals[j][0]) {
                    max_tail = max(max_tail, dp[j]);
                }
            }
            dp[i] = max_tail + 1;
            max_len = max(max_len, dp[i]);
        }
        
        return n - max_len;
    }
};