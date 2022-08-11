#include <iostream>
#include <vector>
#include<map>

typedef long long int ll;

#define Bismillah std::ios_base::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)


std::vector<bool> isprime;

void sieve(ll n) {
    isprime.assign(n + 1, true);
    isprime[0] = isprime[1] = false;

    for (ll j = 4; j <= n; j += 2) {
        isprime[j] = false;
    }
    for (ll i = 3; (i * i) <= n; i += 2) {
        if (!isprime[i]) continue;
        for (ll j = (i * i); j <= n; j += i) {
            isprime[j] = false;
        }
    }
}

int main(){
    Bismillah;
    sieve(1299710);

    ll temp;
    std::cin >> temp;

    while(temp != 0){
        ll back=temp, ford=temp;

        ll cnt = 0;

        for(ford;ford<1299710;ford++){
            if(isprime[ford]){
                break;
            }
            cnt++;
        }

        for(back;back>=2;back--){
            if(isprime[back]){
                break;
            }
            cnt++;
        }

        std::cout << cnt << "\n";

        std::cin >> temp;
    }
}
