#include <vector>
#include <algorithm>
using namespace std;

/*
    Title: 264. Ugly Number II
    Time Complexity: 
        1. O(n)

    Algorithm:
        1. Dynamic Programming
    
    Note:
        1. 這題DP比較隱晦
            i. n >= 1
               已知uglies[1]..uglies[n]為第一小到第n小的ugly number，
               則第n+1小的ugly number一定在{uglies[1]..uglies[n]} * {2, 3, 5} 之間

               proof:
                    令第n+1小的ugly number為k
                    如果k不在{uglies[1]..uglies[n]} * {2, 3, 5}中，
                    因為n >= 1，所以k至少有一個2或3或5的因數
                    => 一定存在一個 a = k/2 或 k/3 或 k/5且不在{uglies[1]..uglies[n]}中
                    
                    a不在{uglies[1]..uglies[n]}中，卻又小於k
                    因此與k是第n+1小的ugly number事實矛盾。
        
        2. 利用n1, n2, n3紀錄現在2, 3, 5分別乘到哪。
        
    Date: 01/03/2022 21:21										
    Time: 0 ms  -- beat 100.00%
    Memory: 6.2 MB  -- beat 81.03%
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        static vector<int> uglies;

        if (uglies.empty()) {
            uglies.push_back(1);
            int n1 = 0, n2 = 0, n3 = 0;
            
            for (int i = 1; i < 1690; i ++) {
                int new_add = min(min(2*uglies[n1], 3*uglies[n2]), 5*uglies[n3]);
                
                if (new_add == 2*uglies[n1]) {
                    n1 += 1;
                }
                if (new_add == 3*uglies[n2]) {
                    n2 += 1;
                }
                if (new_add == 5*uglies[n3]) {
                    n3 += 1;
                }
                uglies.push_back(new_add);
            }
        }
        return uglies[n-1];
    }
};