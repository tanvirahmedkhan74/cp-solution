#include <bits/stdc++.h>

typedef long long int ll;

#define OnekFast std::ios_base::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

std::vector<ll> primeFactors(ll n)
{
    std::vector<ll> factos;

    if (n < 0)
    {
        factos.push_back(-1);
        n *= -1;
    }

    for (ll i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            n /= i;
            factos.push_back(i);
        }
    }

    if (n > 1)
    {
        factos.push_back(n);
    }

    return factos;
}

int main()
{
    OnekFast;
    ll num;
    std::cin >> num;

    while (num != 0)
    {
        std::vector<ll> ans = primeFactors(num);
        std::cout << num << " = ";

        for(int i=0;i< ans.size();i++){
            if(i == ans.size() - 1){
                std::cout << ans[i];
                break;
            }

            std::cout << ans[i] << " x ";
        }

        std::cout << "\n";

        std::cin >> num;
    }
}
