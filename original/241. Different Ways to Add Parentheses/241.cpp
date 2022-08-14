#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*
    Title: 241. Different Ways to Add Parentheses
    Time Complexity: O(4^n / (n^(3/2)))
    Space Complexity: O(4^n / (n^(3/2)))-extra space

    Algorithm: 
        1. Dynamic Programming (Top-Down)
        
    Note:
        1. 這題想問的是在可以隨意增加括號對的情況下，能得到的所有答案。
           我們可以想成「將所有運算符號 (+, -, *) 以任意優先級順序來運算」，
           就可以得到所有可能的答案。

        2. 這題策略有兩種，一種是考慮哪個運算符號先計算，一種是考慮哪個運算符號最後計算，
           兩者都是 Divide & Conquer，也都可以訪問到所有運算順序。

           But, ...
           考慮哪個運算符號最先計算的做法，會遇到 「要判斷該運算符號左右兩邊數字」的問題，
           雖然也可以做，但是麻煩不少。
           相較之下，考慮哪個運算符號最後計算好寫的多，程式碼寫起來非常簡潔，
           
           因此本題我是用考慮哪個最後算的方法。

        3. vector<int> helper(string input):
            Meaning:
                回傳 input 可能產生的所有結果
            
            Divide & Conquer
                遍歷整個字串，如果發現運算符號 (+, -, *)，即以該符號為分隔點，分成左右
                兩個 substring，並將他們丟到 helper，得到左右兩邊所有可能的結果後，
                再一一將左右兩邊的結果根據運算符號組合起來

            Dynamic Programming
                可以用 unordered_map ，以 string 為 key，如此便只剩下 O(n^2) 個 subproblems。

        4. Time Complexity Analysis
            這題的分析方法和 LeetCode 95. Unique Binary Search Trees II 非常相似。

            i. Only Divide & Conquer
                定義長度為 k 的 input string 能產生的最多結果個數 = P(k)

                在最極端的情況，
                T(n) = T(2)+T(n-3) + T(4)+T(n-5) + ... + P(2)xP(n-3) + P(4)xP(n-5) + ...
                和 LeetCode 95. 的寫法超像...

                可以知道 T(n) <= T(1)+T(n-2) + T(2)+T(n-3) + T(3)+T(n-4) + ... + T(n-2)+T(1)
                                + P(1)xP(n-2) + P(2)xP(n-3) + P(3)x(n-4) + ... + P(n-2)xP(1)

                Define C(n) = Catalan Number(n)
                    P(1) = 1 <= C(1) = 1
                    P(2) = 1 <= (2) = 1
                    P(3) = P(1)xP(1) <= C(3) = C(1)xC(1),
                    P(4) = P(1)xP(2) + P(2)xP(1) <= C(4) = C(1)xC(2)+C(2)xC(1)
                    ......
                我們可以得到 P(k) <= C(k), for each k
                所以 T(n) <=  T(1)+T(n-2) + T(2)+T(n-3) + T(3)+T(n-4) + ... + T(n-2)+T(1)
                            + C(1)xC(n-2) + C(2)xC(n-3) + C(3)x(n-4) + ... + C(n-2)xC(1)

                => T(n) = O(n x (n!) + C(n)) (詳細算法在 LeetCode 95. 解法裡有介紹)

            ii. Divide & Conquer with Momorization
                a.  有 n^2 個 subproblems，每個會花 O(n)-time 在處理 Dividing，
                    總共花在 dividing 的時間是 O(n^3)-time

                b.  和 LeetCode 95. 的分析方法一樣，
                    在 combination 上，總共會花 P(n) + 2xP(n-1) + 3xP(n-2) + ... nxP(1) 
                            <= C(n) + 2xC(n-1) + 3xC(n-2) + ... nxC(1) 
                            = O(C(n))-time
                
                c. Total Time Complexity:
                    O(n^3 + C(n)) = O(4^n / (n^(3/2)))-time

    Date: 05/30/2022 04:13												    			
    Time: 0 ms  -- beat 100.00%
    Memory: 7.4 MB  -- beat 82.61%
*/

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        unordered_map <string, vector<int>> memo;
        return helper(expression, memo);
    }
    
    vector<int> helper(string input, unordered_map <string, vector<int>>& memo) {
        if (memo.find(input) != memo.end()) {
            return memo[input];
        }
        
        int n = input.length();
        bool isNum = true;
        
        for (int i = 0; i < n; i ++) {
            char ch = input[i];
            if (ch == '+' || ch == '-' || ch == '*') {
                isNum = false;
                string left_str = input.substr(0, i);
                string right_str = input.substr(i+1, n-1-i);
                vector<int> left_res = helper(left_str, memo);
                vector<int> right_res = helper(right_str, memo);
                
                for (int j = 0; j < left_res.size(); j ++) {
                    for (int k = 0; k < right_res.size(); k ++) {
                        switch (ch) {
                            case '+':
                                memo[input].push_back(left_res[j] + right_res[k]);
                                break;
                            
                            case '-':
                                memo[input].push_back(left_res[j] - right_res[k]);
                                break;
                                
                            case '*':
                                memo[input].push_back(left_res[j] * right_res[k]);
                                break;
                        }
                    }
                }
            }
        }
        
        if (isNum) {
            memo[input].push_back(stoi(input));
        }
        
        return memo[input];
    }
};