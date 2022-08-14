#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
    /*
        Title: 384. Shuffle an Array
        Time Complexity:
            1. O(N)

        Algorithm:
            1. Fisher Yate's Algorithm

        Note:
            1. Fisher Yate's Algorithm(原始版):
                i.   有兩個array，A是放待選數字，B是放已經排序好的數字。
                ii.  每次從A隨機選一個數字，放入B的尾巴，並將選到的數字從A移出。
                     重複以上動作，直到A被清空。
                iii. 每種permutaion都是1/(n!)的機率。
                iv.  時間複雜度： O(N^2)

            2. Fisher Yate's Algorithm(進階版):
                i.   原理同原始版，只是只有A一個array。
                ii.  每次隨機從A[i..n]中選一個數字，將之與A[i]交換
                iii. 重複ii. for i in [0 ~ n]
                iv.  時間複雜度: O(N)

        Date: 12/18/2021 18:13						
        Time: 0ms  -- beat 100.00%
        Memory: 8.1 MB  -- beat 14.39%
    */
public:
    Solution(vector<int>& nums) {
        this -> nums = nums;
        this -> origin = nums;
        srand(time(0));
    }
    
    vector<int> reset() {
        nums = origin;
        return nums;
    }
    
    vector<int> shuffle() {
        for (int i = 0; i < nums.size(); i ++) {
            int pick = i + rand() % (nums.size() - i);
            int temp = nums[i];
            nums[i] = nums[pick];
            nums[pick] = temp;
        }
        return nums;
    }

private:
    vector<int> origin;
    vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */