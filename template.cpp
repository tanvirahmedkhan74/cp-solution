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
