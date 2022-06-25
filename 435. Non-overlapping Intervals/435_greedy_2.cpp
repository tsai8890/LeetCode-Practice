#include <algorithm>
#include <vector>
using namespace std;


/*
    Title: 435. Non-overlapping Intervals
    Time Complexity: O(nlogn) 
    Space Complexity: O(1) - extra space

    Algorithm: 
        1. Greedy
        
    Note:
        1.  這題 brutal force 的解法需要 O(2^n) - time 來找出
            所有可能的 subset ，一定會超時

            把 intervals 排序後，除了可以使用 bottom-up DP 的解法，
            還可以使用 greedy 算法，使時間複雜度降至 O(nlogn)
            
            排序方式可以按照 interval[0] (begin) 或是 interval[1] (end)，
            兩種作法都差不多，這篇的做法是按照 ”“”interval[1] (end)“”“ 來排序 intervals

        2.  Greedy Algorithm 
            best_intervals: 考慮 intervals[i..n-1]，最長的 non-overlapping intervals，
                            若有很多最長的，取第一個 interval.begin 最大的那個
            prev: best_intervals 的第一個 interval 的 index
            count: len(best_intervals)
            
            初始條件：
                prev = -1
                count = 0
                best_intervals = []

            演算法： 
                for i in [n-1..0]:
                    考慮是否加入新 interval: intervals[i]
                    i.  若 intervals[i] 與 best_intervals 不衝突：
                            best_intervals.push_front(intervals[i])
                            count += 1
                            prev = i
                    
                    ii. 若衝突 且 intervals[prev][0] < intervals[i][0]：
                            best_intervals.pop_front()
                            best_intervals.push_front(intervals[i])
                            prev = i
                    
                    iii. Otherwise：
                        continue

        3.  Explanation of Greedy Algorithm
            Similar to that in 435_greedy_1.cpp

        4.  Total Time Complexity = O(nlogn)
            Total Space Complexity = O(1)
    
    Date: 06/25/2022 22:41																		    			
    Time: 516 ms  -- beat 77.83%
    Memory: 89.8 MB  -- beat 45.92%
*/

class Solution {
public:
    static bool cmp_by_end(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp_by_end);
        
        int count = 0, prev = -1;
        for (int i = n-1; i >= 0; i --) {
            if (prev == -1) {
                count += 1;
                prev = i;
            }
            else if (intervals[i][1] <= intervals[prev][0]) {
                count += 1;
                prev = i;
            }
            else {
                if (intervals[prev][0] < intervals[i][0]) {
                    prev = i;
                }
            }
        }
        return n - count;
    }
};