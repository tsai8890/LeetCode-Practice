#include <vector>
#include <queue>
using namespace std;

/*
    Title: 313. Super Ugly Number
    Time Complexity: 
        1. O(n*logk)
            i. k = primes.size()

    Algorithm:
        1. Dynamic Programming
        2. Priority Queue
    
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
        
        2. 這題和264. Ugly Number II幾乎一樣，只差在primes的數量不同。
           但是因為這題k=primes.size()<=1000, n<=10^6，如果按照264.的做法，
           複雜度會是O(n*k)，會TLE。

           因此，這題可以使用priority queue，讓時間複雜度降到O(nlogk)
        
    Date: 01/04/2022 00:28										
    Time: 1491 ms  -- beat 42.54%
    Memory: 18.6 MB  -- beat 18.18%
*/

struct prime {
    int index;
    long long result;
    
    prime(int index, long long result) {
        this->index = index;
        this->result = result;
    }
};

bool operator<(prime a, prime b)
{
    return a.result > b.result;
}

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ptr(primes.size(), 0);
        vector<int> nums = {1};
        
        priority_queue<prime> prime_queue;
        for (int j = 0; j < ptr.size(); j ++) {
            prime newUgly(j, primes[j]*nums[ptr[j]]);
            prime_queue.push(newUgly);
        }
        
        while (nums.size() < n) {
            auto item = prime_queue.top();
            prime_queue.pop();
            
            int index = item.index;
            long long newUgly = item.result;
            if (newUgly != nums.back())
                nums.push_back(newUgly);
            
            prime new_add(index, (long long)primes[index] * nums[ptr[index]+1]);
            prime_queue.push(new_add);
            ptr[item.index] += 1;
        }
        
        return nums[n-1];
    }
};