#include <vector>
#include <algorithm>
using namespace std;

#define NOT_TRIED -1

/*
    Title: 877. Stone Game
    Time Complexity: O(1)
    Space Complexity: O(1)-extra space

    Algorithm: 
        1. Fantastic Mathematics
        
    Note:
        1. 這題其實可以觀察之後直接得出結論，
           那就是，先拿的百分之百會贏。

           假設有一開始有 n 個石頭
           i.   如果 n = 2, 那先拿的一定贏

           ii.  如果 n = 4, 那先拿的可以自由選擇拿 第一個+第三個 或 第二個+第四個，
                      因為石頭分數總和是奇數，一定有一個組合比較大，因此只要選比較大的組合拿就可以贏
           
           iii. 以此類推，只要先拿的都可以選擇拿 所有奇數位置的石頭 或 所有偶數位置的石頭，因此一定可以贏
           
           iv. 以上的思路可以用數學歸納法很快地證明，因此保證是對的

        2. 由第一點可知，只要回傳 true 就可以了

    Date: 05/23/2022 23:15															
    Time: 0 ms  -- beat 100.00%
    Memory: 7.6 MB  -- beat 69.68%
*/

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};