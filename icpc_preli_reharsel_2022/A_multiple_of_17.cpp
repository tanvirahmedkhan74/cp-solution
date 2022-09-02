#include <bits/stdc++.h>

typedef long long int ll;

#define digPs(n) std::fixed << std::setprecision(n)

#define SheiFast std::ios_base::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);

int main(){
    SheiFast;
    
    ll num;

    std::cin >> num;

    while(num != 0){
        ll temp = num;
        int last_dig = num % 10;

        temp /= 10;

        ll div = temp - (5*last_dig);

        if(div % 17 == 0){
            std::cout << 1 << "\n";
        }else std::cout << 0 << "\n";

        std::cin >> num;
    }
}