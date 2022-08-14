#include <vector>
using namespace std;

/*
    Title: 376. Wiggle Subsequence
    Time Complexity: O(n)
    Space Complexity: O(n)-extra space

    Algorithm: 
        1. Dynamic Programming (Bottom-Up)
        2. Greedy
        
    Note:
        1.  這題可以使用 DP + Greedy，時間複雜度可以做到 O(n)
        
        2.  Dynamic Programming (與先前的 dp array 定義不同):
            up[i]:   可以使用nums[0..i]，且最後一個元素是 wiggle up 的最長 wiggle subsequence 的長度
            down[i]: 可以使用nums[0..i]，且最後一個元素是 wiggle down 的最長 wiggle subsequence 的長度
            
            Hint (內容比較長，如果都懂可以跳過)
                i.  abs(up[i] - down[i]) <= 1
                    Explanation:
                        若up[i] = k，則去掉該 wiggle subsequence 的最後一個元素，
                        就變成另一個長度為 k-1，且結尾是 wiggle down 的 wiggle subsuquence 了
                        所以 down[i] 至少 >= up[i] - 1
                        反之亦然，up[i] 至少 >= down[i] - 1

                        因此，abs(up[i] - down[i]) <= 1

                ii. DP Transition 分析
                    - 若 nums[i-1] < nums[i]
                        a.  down[i] = down[i-1]
                            
                            Explanation:
                                case I.
                                    考慮 down[i]，若不使用 nums[i] 作為新的結尾，則 down[i] = down[i-1]
                                
                                case II. 
                                    若 down[i] 以 nums[i] 為結尾，則必須找到「在 nums[0..i-1] 中結尾是
                                    wiggle up 的 subsequence」，暫時叫他 seq1

                                    在以 nums[i] 為結尾的情況，且 seq1 可以接 nums[i] 的情況下，
                                    down[i] = len(seq1) + 1
                                    
                                    可以保證 len(seq1) + 1 <= down[i-1] for all seq1：
                                    Proof：
                                        對於任何可以接上 nums[i] 的 seq1，
                                        令其最後一個元素是 x，則 x > nums[i] (因為seq1 可以接 nums[i])
                                        同時，x > nums[i-1] (因為 x > nums[i] && nums[i] > nums[i-1])

                                        因此，seq1 也可以接上 nums[i-1]
                                        
                                        因為 down[i-1] 考慮了所有 nums[0..i-1] 中可能的 wiggle subsequence，
                                        並選了最長的那個，因此 {seq1 + nums[i]} 這樣的 sequence 一定會被
                                        down[i-1] 考慮過

                                        => for all seq1,
                                            down[i-1] >= len({seq1 + nums[i]}) >= len(seq1) + 1 

                                    所以 down[i] = len(seq1) + 1 <= down[i-1]

                                考慮 case I, II，down[i] = down[i-1]

                        b.  up[i] = down[i-1] + 1
                            
                            Explanation:
                                case I.
                                    考慮 up[i]，若不使用 nums[i] 作為新的結尾，則 up[i] = up[i-1]
                                
                                case II. 
                                    若 up[i] 結尾是 nums[i]，則必須找到「在 nums[0..i-1] 中結尾是
                                    wiggle down 的 subsequence」，暫時叫他 seq1

                                    這裡可以保證：
                                        最長且可以和nums[i]接起來的 seq1，長度和 down[i-1] 一樣 

                                        Proof：
                                            直接使用 down[i-1] 的 subsequence 來當 seq1
                                            令 seq1 最後一個元素為 x

                                            i.  if x < nums[i-1] => x < nums[i-1] < nums[i]
                                                則 seq1 可以直接接上 nums[i]
                                                => seq1 的長度 == down[i-1]

                                            ii. if x >= nums[i-1]
                                                因為 x >= nums[i-1]，且 seq1 為 wiggle down 結尾
                                                所以可以將 seq1 的最後一個元素 x 換成 nums[i-1]

                                                因為 nums[i-1] < nums[i]，
                                                所以修改後的 seq1 可以直接接上 nums[i]，
                                                且修改後的 seq1 長度也是 down[i-1]
                                                => seq1 的長度 == down[i-1]
                                    所以 up[i] = down[i-1] + 1
                                
                                考慮 case I., II., 
                                    up[i] = max(up[i-1], down[i-1] + 1)
                                    結合 [Hint i.] => up[i] = down[i-1] + 1
                    
                    - 若 nums[i-1] > nums[i]
                        因為證明具有對稱性，所以會有以下相似結果
                        a. up[i] = up[i-1]
                        b. down[i] = up[i-1] + 1

                    - 若 nums[i-1] == nums[i]
                        a. up[i] = up[i-1]
                        b. down[i] = down[i-1]
                        
                        證明手法和「若 nums[i-1] < nums[i] 的 a.」一樣

            DP Transition
                i.  nums[i-1] < nums[i]
                        up[i] = down[i-1] + 1
                        down[i] = down[i-1]
                
                ii. nums[i-1] > nums[i]
                        up[i] = up[i-1]
                        down[i] = up[i-1] + 1

                iii. nums[i-1] = nums[i]
                        up[i] = up[i-1]
                        down[i] = down[i-1]

        3.  時間複雜度： O(n)
                # subproblems = O(n)
                # cost each subproblem = O(1)
                Total Time Complexity: O(n)
            
            空間複雜度： O(n)

        4.  這個解法的證明很不直覺，但是很 greedy (省略了找上一個元素的過程)，
            非常值得一看

    Date: 06/06/2022 21:52																	    			
    Time: 0 ms  -- beat 100.00%
    Memory: 7.2 MB  -- beat 42.43%
*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> up(n, 0);
        vector<int> down(n, 0);
        
        for (int i = 0; i < n; i ++) {
            if (i == 0) {
                up[i] = 1;
                down[i] = 1;
            }
            else {
                if (nums[i-1] < nums[i]) {
                    up[i] = down[i-1] + 1;
                    down[i] = down[i-1];
                }
                else if (nums[i-1] > nums[i]) {
                    up[i] = up[i-1];
                    down[i] = up[i-1] + 1;
                }
                else {
                    up[i] = up[i-1];
                    down[i] = down[i-1];
                }
            }
        }
        return max(up.back(), down.back());
    }
};