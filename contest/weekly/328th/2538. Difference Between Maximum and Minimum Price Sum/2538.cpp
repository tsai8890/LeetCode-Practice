#include <algorithm>
#include <vector>
#include <map>
using namespace std;

/*
    DFS + DP
*/

class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> adjList(n, vector<int>());
        for (int i = 0; i < edges.size(); i ++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        
        long long ans = 0;
        map<pair<int, int>, long long> dp;
        for (int i = 0; i < n; i ++) {
            long long maxSum = maxPath(i, -1, adjList, price, dp);
            ans = max(ans, maxSum - price[i]);
        }
        return ans;
    }
    
    long long maxPath(int n, int parent, vector<vector<int>>& adjList, vector<int>& price, map<pair<int, int>, long long>& dp) {
        if (dp.find(make_pair(n, parent)) != dp.end()) {
            return dp[make_pair(n, parent)];
        }
        
        long long maxVal = 0;
        for (int i = 0; i < adjList[n].size(); i ++) {
            if (parent != adjList[n][i]) {
                long long childMax = maxPath(adjList[n][i], n, adjList, price, dp);
                maxVal = max(maxVal, childMax);
            }
        }
        dp[make_pair(n, parent)] = maxVal + price[n];
        return maxVal + price[n];    
    }
};