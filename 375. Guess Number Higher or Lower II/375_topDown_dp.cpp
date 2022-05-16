#include <climits>
#include <algorithm>
using namespace std;

#define NOT_TRIED -1

/*
    Title: 375. Guess Number Higher or Lower II
    Time Complexity: O(n^3)
    Space Complexity: O(n^2)-extra space

    Algorithm: 
        1. TopDown DP (Divide & Conquer + Memorization)
        
    Note:
        1. 這題想問的是最少需要花多少錢才能猜中數字，其實隱含的意思是
           要考慮最壞的情況。如果不用考慮最壞的情況，那麼最少花0元就可以猜到了
           (一猜就中)。
           
           因此，題目要求的是「無論情況有多壞，我們最少需要花多少錢一定可以猜中數字」。

           對於這個題目，我們可以用 Minimax Search (a.k.a. Game Tree)來解決。
           Minimax Search Algorithm: 
           https://mropengate.blogspot.com/2015/04/ai-ch4-minimax-alpha-beta-pruning.html
        
           MinNode: 給定一個 [left, right] 猜測區間，
                    逐個討論「在right-left+1種猜測中」哪個cost最小，
                    並遞迴給MaxNode

           MaxNode: MinNode針對[left, right]猜測數字k時，
                    MaxNode要將 [left,k-1], [k+1,right] 遞迴給 MinNode，
                    並根據結果選最大的cost
           
           以上的演算法可以簡化為以下的 Transition function:
           minCost(left, right) = min(k + max(minCost(left,k-1), minCost(k+1,right))),
                                  for k in [left, right]
           
           可以使用 Divide & Conquer / Dynamic Programming 來解

        2. 這題如果只用Divide & Conquer來做，根據Time function: T(n) = n * T(n-1) + n，
           時間複雜度會達到O(n!)，一定會TLE。 
           因此，需要搭配Memorization來做TopDown DP，這樣時間複雜度可以降到 O(n^3)。 
           (# of problems = O(n^2)) x (size of each problem = O(n)) = O(n^3)

    Date: 05/16/2022 14:02													
    Time: 240 ms  -- beat 36.15%
    Memory: 8.2 MB  -- beat 41.61%
*/

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> memo(n+1, vector<int>(n+1, NOT_TRIED));
        return helper(1, n, memo);
    }
    
    int helper(int left, int right, vector<vector<int>>& memo) {
        if (left >= right) {
            return 0;
        }
        else if (memo[left][right] != NOT_TRIED) {
            return memo[left][right];
        }
        else {
            int minCost = INT_MAX;
            for (int i = left; i <= right; i ++) {
                minCost = min(minCost, i + max(helper(left, i-1, memo), helper(i+1, right, memo)));
            }
            memo[left][right] = minCost;
            return memo[left][right];
        }
    }
};