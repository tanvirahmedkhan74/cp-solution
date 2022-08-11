#include <bits/stdc++.h>

typedef unsigned long long int ll;

#define OnekFast std::ios_base::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

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


int main(){
    OnekFast;
    ll num;
    std::cin >> num;

    while(num != 0){
        
        for(auto i: primeFactors(num)){
            std::cout << i.first << "^" << i.second << " ";
        }

        std::cout << "\n";

        std::cin >> num;
    }
}
