#include <bits/stdc++.h>

typedef long long int ll;

#define error 10e-8
#define digPs(n) std::fixed << std::setprecision(n)
#define OnekFast std::ios_base::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

ll fast_pow(ll base, ll raise, ll mod){
    ll ans = 1;

    while(raise > 0){
        if (raise&1){
            ans = (ans * base) % mod;
        }

        base = (base * base) % mod;
        raise >>= 1;
    }

    return ans % mod;
}

void sieve(ll n)
{
    isprime.assign(n + 1, true);
    isprime[0] = isprime[1] = false;

    for (ll j = 4; j <= n; j += 2)
    {
        isprime[j] = false;
    }
    for (ll i = 3; (i * i) <= n; i += 2)
    {
        if (!isprime[i])
            continue;
        for (ll j = (i * i); j <= n; j += i)
        {
            isprime[j] = false;
        }
    }
}

std::map<ll, int> primeFactors(ll n){
    std::map<ll, int> factos;

    for(ll i=2;i * i <= n;i++){
        if(n % i == 0){
            factos.insert(std::make_pair(i, 0));
            while(n % i == 0){
                n /= i;
                factos[i] += 1;
            }
        }
    }

    if(n > 1){
        factos.insert(std::make_pair(n, 1));
    }

    return factos;
}


ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

int factorialTrailingZeroes(ll n){
    ll ans = 0;

    while(n / 5){
        ans += (n/5);
        n /= 5;
    }

    return ans;
}

ll binarySearch(std::vector<ll> &vec, ll l, ll r, ll target){
    ll mid = l + (r- l) / 2;
    if(l <= r ){
        if(vec[mid] == target){
            return mid;
        }else if(vec[mid] > target){
            return binarySearch(vec, l, mid - 1, target);
        }else return binarySearch(vec, mid + 1, r, target);
    }else{
        return mid;
    }
}

int binary_search_lowerbound(const vector<int>& a, int key) {
    int res = a.size();
    int l = 0, r = a.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] >= key) {
            res = mid;
            r = mid - 1;
        } else /* if (a[mid] < key) */ {
            l = mid + 1;
        }
    }
    return res;
}
 
// upperbound(x) = position of first element y such that y > x 
int binary_search_upperbound(const vector<int>& a, int key) {
    int res = a.size();
    int l = 0, r = a.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] > key) {
            res = mid;
            r = mid - 1;
        } else /* if (a[mid] < key) */ {
            l = mid + 1;
        }
    }
    return res;
}
 
// precision handling
// x = 1.7 (actrually 1.70000234 or even 1.6999962)
// if (x == 1.7)
 
const double eps = 1e-9; // == 0.000000001
 
bool is_equal(double x, double y) {
    return abs(x - y) <= eps;
}
 
// 1.600000001 < 1.600000002 (diff == 1e-9)
 
bool is_less(double x, double y) {
    return x + eps < y;
}
 
bool is_greater(double x, double y) {
    return is_less(y, x);
}
 
// 0, 0.01, ..., 0.25, ..., 0.49, ..., 0.50, ..., 0.51, ..., 1.0
//               ^n                    ^sqrt(n)
// n = 0.25 => expected answer = 0.50
 
double square_root(double n) {
    assert(n >= 0);
    double l = 0, r = (n + eps < 1 ? 1 : n);
    while (l < r) {
        double mid = (l + r) / 2;
        double mid_squared = mid * mid;
        if (is_equal(mid_squared, n)) {
            return mid;
        } else if (is_less(mid_squared, n)) {
            l = mid;
        } else /* if (is_greater(mid_squared, n)) */ {
            r = mid;
        }
    }
    return l;
}
