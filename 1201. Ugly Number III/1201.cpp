#include <vector>
#include <climits>
using namespace std;

/*
    Title: 1201. Ugly Number III
    Time Complexity: 
        1. O(logn), n <= 10^9

    Algorithm:
        1. Binary Search
        2. Mathematics...
    
    Note:
        1. gcd(最大公因數)跟lcm(最小公倍數)要記！
        2. lcm(a, b) = a * b / gcd(a, b)
        
    Date: 01/03/2022 23:41										
    Time: 0 ms  -- beat 100.00%
    Memory: 6 MB  -- beat 30.29%
*/

long long int gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    else {
        return gcd(b, a % b);
    }
}

long long int lcm(long long int a, long long int b)
{
    return (long long int)(a*b) / gcd(a, b);
}

long long int lcm(long long a, long long b, long long c)
{
    return lcm(a, lcm(b, c));
}

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        if (a == 1 && b == 1 && c == 1)
            return n;
        
        long long l_a = (long long)a;
        long long l_b = (long long)b;
        long long l_c = (long long)c;
        
        vector<long long int> lcm_arr;
        lcm_arr.push_back(lcm(l_a, l_b));
        lcm_arr.push_back(lcm(l_b, l_c));
        lcm_arr.push_back(lcm(l_a, l_c));
        lcm_arr.push_back(lcm(a, b, c));
        
        int left = 1, right = INT_MAX;
        while (left <= right) {
            int mid = left + (right-left)/2;
            int count = total_count(mid, a, b, c, lcm_arr);
            
            if (count > n) {
                right = mid - 1;    
            } 
            else if (count < n) {
                left = mid + 1;
            }
            else {
                if (left == right)
                    return left;
                right = mid;
            }
        }
        return -1;
    }
    
    int total_count(long long n, long long a, long long b, long long c, vector<long long>& lcm_arr) {
        int count = n/a + n/b + n/c;
        for (int i = 0; i < 3; i ++)
            count -= n / lcm_arr[i];
        count += n / lcm_arr[3];
        return count;
    }
};