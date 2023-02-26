#define ll long long

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        ll l = 0, r = 2000000000;
        while (l < r) {
            ll mid = (l+r)/2;
            if (count(mid, a, b, c) >= n) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }

    ll gcd(ll a, ll b) {
        if (b > a) {
            ll tmp = a;
            a = b;
            b = tmp;
        }
        while (b > 0) {
            ll tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }

    ll lcm(ll a, ll b) {
        return a*b/gcd(a,b);
    }

    ll count(ll k, ll a, ll b, ll c) {
        return k/a + k/b + k/c 
                - k/lcm(a,b)- k/lcm(b,c) - k/lcm(a,c)
                + k/lcm(lcm(a,b), c);
    }
};