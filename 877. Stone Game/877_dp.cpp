#include <vector>
#include <algorithm>
using namespace std;

#define NOT_TRIED -1

/*
    Title: 877. Stone Game
    Time Complexity: O(n^2)
    Space Complexity: O(n^2)-extra space

    Algorithm: 
        1. Dynamic Programming (Top-Down)
        2. Minimax Search
        
    Note:
        1. 這題是典型的 Minimax Search 題型，有兩個agent互為競爭對手，
           且兩個 agent 的分數和為一個定值，是一個廣義的零和遊戲。

           Minimax Search Algorithm: 
           https://mropengate.blogspot.com/2015/04/ai-ch4-minimax-alpha-beta-pruning.html
        
           minNode(對手最佳化): 
                    給定一個 stones[left .. right] 的石頭序列，
                    分別討論對手拿左邊或拿右邊哪個可以讓自己獲得最少分數，
                    並回傳自己可獲得的最少分數給 maxNode

           maxNode(自己最佳化): 
                    給定一個 stones[left .. right] 的石頭序列，
                    分別討論自己拿左邊或拿右邊哪個可以讓自己獲得最多分數，
                    並回傳自己可獲得的最大分數給 minNode
           
           以上的演算法可用以下的 Transition function 來表達:
                i.  maxNode(left, right) = max(stones[left] + minNode(left+1, right),
                                           stones[right] + minNode(left, right-1))
                
                ii. minNode(left, right) = min(minNode(left+1, right), minNode(left, right-1))

        2. 這題可以使用 Divide & Conquer / Dynamic Programming 來解
           這份 code 是使用 top-down DP 作為解法

    Date: 05/23/2022 22:52															
    Time: 46 ms  -- beat 15.38%
    Memory: 25.3 MB  -- beat 6.61%
*/

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> min_dp(n, vector<int>(n, NOT_TRIED));
        vector<vector<int>> max_dp(n, vector<int>(n, NOT_TRIED));
        
        int total_scores = 0;
        for (int i = 0; i < n; i ++) {
            total_scores += piles[i];
        }
        
        int maxScore = maxNode(piles, 0, n-1, min_dp, max_dp);
        return maxScore > (total_scores - maxScore);
    }
    
    int maxNode(vector<int>& piles, int left, int right, 
                vector<vector<int>>& min_dp, vector<vector<int>>& max_dp) {
        if (left > right) {
            return 0;
        }
        else {
            if (max_dp[left][right] == NOT_TRIED) {
                int pickLeft = piles[left] + maxNode(piles, left+1, right, min_dp, max_dp);
                int pickRight = piles[right] + maxNode(piles, left, right-1, min_dp, max_dp);
                max_dp[left][right] = max(pickLeft, pickRight);
            }
            return max_dp[left][right];
        }
    }
    
    int minNode(vector<int>& piles, int left, int right, 
                vector<vector<int>>& min_dp, vector<vector<int>>& max_dp) {
        if (left > right) {
            return 0;
        }
        else {
            if (min_dp[left][right] == NOT_TRIED) {
                int pickLeft = maxNode(piles, left+1, right, min_dp, max_dp);
                int pickRight = maxNode(piles, left, right-1, min_dp, max_dp);
                min_dp[left][right] = min(pickLeft, pickRight);
            }
            return min_dp[left][right];
        }
    }
};