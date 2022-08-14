#include <string>
#include <vector>
using namespace std;

#define TRUE 1
#define FALSE 0
#define NOT_TRIED -3

#define ans_list vector<vector<string>>

/*
    Title: 131. Palindrome Partitioning
    Time Complexity: O(N x (2^N))
    Space Complexity: O(N^2) - extra space

    Algorithm: 
        1. Depth First Search
        2. Dynamic Programming (Top-Down)
        
    Note:
        1.  因為這題是求組合的題目(且要回傳所有組合)，所以 brutal force 就是最佳解法了， 
            這題最佳解法需要 O(N x 2^N)-time，
            worst case 需要產生O(2^N)大小的 recursion tree，
            每個 recursion node 需要其 parent 花 O(N)-time 來產生 substring + 檢查回文，
            所以全部的時間複雜度是 O(2^N) x O(N) = O(N x 2^N)

        2.  如同所有的求組合/子集合題目，切割子問題的方法通常有兩種，
                i.  要不要選最後一個元素(or 第一個)
                ii. 最後一個選的元素是誰(or 第一個)
            
            這個解法是使用 ii. 第一個選的元素是誰
            並且，這題使用的是 DFS 的方式，只在 recursion 的 base case 才將解加入 result，
            避免了 Divide & Conquer 中因為傳遞解所多花的時間

            Note:   在組合/子集合題目，通常 DFS 會比 Divide & Conquer 快+省空間，
                    只有在不能使用 DFS 的情況，再考慮 Divide & Conquer 的解法

        3.  這題可以使用 DP 減少檢查回文的時間，原本的時間複雜度
            應該是 O(2^N) x {O(N) for 檢查回文 + O(N) for 產生 substring}，
            加上紀錄回文的 DP 後，可以達到 O(2^N) x O(N for 產生 substring)
            
            複雜度上是一樣的，但是常數上少了一倍，值得使用

        4.  Total Time Complexity: O(N x (2^N))
            Total Space Complexity: O(N^2)
                i.  遞迴深度最大是 O(N)，每個 node 都是 O(1)-space，只有 leaf node
                    有 O(N)-space，綜合起來還是 O(N)

                ii. 檢查回文的 DP 陣列需要 O(N^2)-space
            
    Date: 06/28/2022 21:14																			    			
    Time: 104 ms  -- beat 96.81%
    Memory: 49.2 MB  -- beat 91.28%
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        ans_list result; 
        vector<string> curList;
        vector<vector<int>> palin_dp(n, vector<int>(n, NOT_TRIED));
        
        dfs(0, s, curList, result, palin_dp);
        return result;
    }
    
    bool is_palindrome(string& s, int left, int right, vector<vector<int>>& palin_dp) {
        if (palin_dp[left][right] != NOT_TRIED) {
            return palin_dp[left][right] == TRUE;
        }
        
        int n = right - left + 1;
        for (int i = 0; i < n / 2; i ++) {
            if (s[left+i] != s[left+n-1-i]) {
                palin_dp[left][right] = FALSE;
                return false;
            }
        }
        palin_dp[left][right] = TRUE;
        return true;
    }
    
    void dfs(int start, string& s, vector<string>& curList, ans_list& result, vector<vector<int>>& palin_dp) {
        if (start >= s.length()) {
            result.push_back(curList);
            return;
        } 
        
        for (int i = start; i < s.length(); i ++) {
            if (is_palindrome(s, start, i, palin_dp)) {
                curList.push_back(s.substr(start, i-start+1));
                dfs(i+1, s, curList, result, palin_dp);
                curList.pop_back();
            }
        }
    }
};