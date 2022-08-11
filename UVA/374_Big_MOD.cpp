#include <bits/stdc++.h>

typedef long long int ll;
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

int main(){
    OnekFast;
    ll b, p, m;

    while(std::cin >> b >> p >> m){
        std::cout << fast_pow(b, p, m) << "\n";
    }
}
