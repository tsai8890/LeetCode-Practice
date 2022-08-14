#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

#define TRUE 1
#define FALSE 0
#define NOT_TRIED -3

/*
    Title: 131. Palindrome Partitioning
    Time Complexity: O(N x (2^N))
    Space Complexity: O(2^N) - extra space

    Algorithm: 
        1. Divide & Conquer
        2. Dynamic Programming
        
    Note:
        1.  因為這題是求組合的題目(且要回傳所有組合)，所以 brutal force 就是最佳解法了， 
            這題最佳解法需要 O(N x 2^N)-time，
            worst case 需要產生O(2^N)大小的 recursion tree，
            每個 recursion node 需要其 parent 花 O(N)-time 來產生 substring + 檢查回文，
            所以全部的時間複雜度是 O(2^N) x O(N) = O(N x 2^N)

        2.  如同所有的求組合/子集合題目，切割子問題的方法通常有兩種，
                i.  要不要選最後一個元素(or 第一個)
                ii. 最後一個選的元素是誰(or 第一個)
            
            這個解法是使用 i. 第一個選的元素是誰
            並且，這題使用的是 Divide & Conquer 的方式，相較 DFS 在傳遞解上會多花很多時間

            Note:   在組合/子集合題目，通常 DFS 會比 Divide & Conquer 快+省空間，
                    只有在不能使用 DFS 的情況，再考慮 Divide & Conquer 的解法

        3.  這題可以使用 DP 減少檢查回文的時間，原本的時間複雜度
            應該是 O(2^N) x {O(N) for 檢查回文 + O(N) for 產生 substring}，
            加上紀錄回文的 DP 後，可以達到 O(2^N) x O(N for 產生 substring)
            
            複雜度上是一樣的，但是常數上少了一倍，值得使用

        4.  Total Time Complexity: O(N x 2^N)
                i.  O(2^N) 個 recursion node 要花的時間
                    a. 其parent 檢查回文 + 產生 substring: O(N)-time
                    b. 將解合併 + 回傳:
                        第一層有一個 node: O(2^N)
                        第二層有兩個 node: 2 x O(2^(N-1)) = O(2^N)
                        第三層有兩個 node: 4 x O(2^(N-2)) = O(2^N)
                        ...
                        ...
                        第 N 層有 2^N 個 node: 2^N x O(1) = O(2^N)

                        總和: O(N x 2^N)

                ii. 所以 total time complexity = O(N x 2^N)，
                    這個解法慢就慢在 i-b. 部分，雖然複雜度和 DFS 一樣都是 O(N x 2^N)，
                    但是可以看到慢超級多

            Total Space Complexity: O(N^2)
                i.  遞迴深度最大是 O(N)，單一遞迴路徑最大使用
                    空間是 O(2^N)，因為要傳遞解

                ii. 檢查回文的 DP 陣列需要 O(N^2)-space
    
    Date: 06/29/2022 01:09																		    			
    Time: 1518 ms  -- beat 5.01%
    Memory: 565 MB  -- beat 5.04%
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<int>> palin_dp(n, vector<int>(n, NOT_TRIED));
        return helper(n-1, n-1, s, palin_dp);
    }
    
    bool is_partition(string& s, int left, int right, vector<vector<int>>& palin_dp) {
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
    
    vector<vector<string>> helper(int n, int right, string& s, vector<vector<int>>& palin_dp) {
        if (n == 0) {
            if (is_partition(s, 0, right, palin_dp)) {
                return vector<vector<string>> {vector<string>{s.substr(0, right+1)}};
            }
            else {
                return vector<vector<string>>();
            }
        }
        else {
            vector<vector<string>> res1 = helper(n-1, right, s, palin_dp);
            vector<vector<string>> total_result;
            if (res1.size() != 0) {
                total_result.insert(total_result.end(), res1.begin(), res1.end());
            }
            
            if (is_partition(s, n, right, palin_dp)) {
                vector<vector<string>> res2 = helper(n-1, n-1, s, palin_dp);
                if (res2.size() != 0) {
                    string tail = s.substr(n, right-n+1);
                    for (auto& v: res2) {
                        v.push_back(tail);
                        total_result.push_back(v);
                    }
                }
            }
            return total_result;
        }
    }
};