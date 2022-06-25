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
            兩種作法都差不多，這篇的做法是按照 ”“”interval[0] (begin)“”“ 來排序 intervals

        2.  Greedy Algorithm 
            best_intervals: 考慮 intervals[0..i]，最長的 non-overlapping intervals，
                            若有很多最長的，取最後一個 interval.end 最小的那個
            prev: best_intervals 的最後一個 interval 的 index
            count: len(best_intervals)
            
            初始條件：
                prev = -1
                count = 0
                best_intervals = []

            演算法： 
                for i in [0..n-1]:
                    考慮是否加入新 interval: intervals[i]
                    i.  若 intervals[i] 與 best_intervals 不衝突：
                            best_intervals.append(intervals[i])
                            count += 1
                            prev = i
                    
                    ii. 若衝突 且 intervals[prev][1] > intervals[i][1]：
                            best_intervals.pop()
                            best_intervals.append(intervals[i])
                            prev = i
                    
                    iii. Otherwise：
                        continue

        3.  Explanation of Greedy Algorithm
            當考慮 intervals[i]，
            best_intervals 一定只有兩種可能：
                i. 包含 intervals[i]
                    i-i.    若 intervals[i] 與 best_intervals 不衝突
                            則 此時最佳解為 best_intervals + intervals[i]

                    i-ii.   若 intervals[i] 與 best_intervals 衝突
                            此時最佳解長度一定為 len(best_intervals) = count

                            又分為兩種情況
                            a. intervals[prev].begin < intervals[i].begin < intervals[i].begin < intervals[prev].end
                                如果是這種情況，
                                則 best_intervals 要 pop 掉 intervals[prev]，
                                再 加入 intervals[i]
                            
                            b. Otherwise
                                維持原本的 best_intervals 即可

                ii. 不包含 intervals[i]
                    維持原本的 best_intervals 即可

        4.  Total Time Complexity = O(nlogn)
            Total Space Complexity = O(1)
    
    Date: 06/25/2022 22:08																		    			
    Time: 481 ms  -- beat 87.82%
    Memory: 89.9 MB  -- beat 45.92%
*/

class Solution {
public:
    static bool cmp_by_begin(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp_by_begin);
        
        int count = 0, prev = -1;
        for (int i = 0; i < n; i ++) {
            if (prev == -1) {
                count += 1;
                prev = i;
            }
            else if (intervals[prev][1] <= intervals[i][0]) {
                count += 1;
                prev = i;
            }
            else {
                if (intervals[prev][1] > intervals[i][1]) {
                    prev = i;
                }
            }
        }
        return n - count;
    }
};