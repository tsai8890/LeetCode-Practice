#include <vector>
using namespace std;

#define NOT_TRIED_YET -2
#define NO_RESULT -1

/*
    Title: 787. Cheapest Flights Within K Stops
    Time Complexity: O(V^2 x K)
    Space Complexity: O(V x K)-extra space

    Algorithm: 
        1. Top-Down DP (Divide & Conquer + Memorization)
        
    Note:
        1. 這題有很多解法，Divide&Conquer是最直接可以想到的。
           但是Divide & Conquer原本若不允許拜訪重複的點(使用visited array)，
           那麼在使用memorization加速的時候會變得很麻煩，
           需要考慮(node id, visited state, remaining steps)三個key，
           因此實作上允許拜訪重複的點，而且並不會讓整個程式陷入無窮迴圈，因為總共只會有O(VxK)個子問題，
           每個子問題也只需要O(V)-time，因此時間複雜度可以達到O(V^2 X K)

        2. 
    Date: 05/11/2022 04:22										
    Time: 37 ms  -- beat 68.76%
    Memory: 15.3 MB  -- beat 32.33%
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector< vector< vector<int> > > edges(n, vector< vector <int> >());
        for (int i = 0; i < flights.size(); i ++) {
            int from = flights[i][0];
            int to = flights[i][1];
            int price = flights[i][2];
            vector<int> add_edge = {to, price};
            edges[from].push_back(add_edge);
        }
        
        vector<vector<int>> memo(n, vector<int>(k+2, NOT_TRIED_YET));
        return cheapest(src, dst, k, 0, edges, memo);
    }
    
    int cheapest(int curPos, int dst, int k, int steps,
                 vector<vector<vector<int>>>& edges, vector<vector<int>>& memo) {
        
        if (steps >= k+2) {
            return NO_RESULT;
        }
        else if (memo[curPos][steps] != NOT_TRIED_YET) {
            return memo[curPos][steps];
        }
        else if (curPos == dst) {
            memo[curPos][steps] = 0;
            return memo[curPos][steps];
        }
        else {
            int minCost = NO_RESULT;
            for (int i = 0; i < edges[curPos].size(); i ++) {
                int nextPos = edges[curPos][i][0];
                int edgeCost = edges[curPos][i][1];
                
                int temp = cheapest(nextPos, dst, k, steps+1, edges, memo);
                if (temp != NO_RESULT) {
                    int curCost = edgeCost + temp;
                    if (minCost == NO_RESULT || curCost < minCost) {
                        minCost = curCost;
                    }
                }
            }
            memo[curPos][steps] = minCost;
            return memo[curPos][steps];
        }
    }
};