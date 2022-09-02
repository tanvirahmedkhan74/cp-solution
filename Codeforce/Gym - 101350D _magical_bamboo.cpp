#include <bits/stdc++.h>

typedef long long int ll;

#define error 10e-8
#define digPs(n) std::fixed << std::setprecision(n)
#define OnekFast std::ios_base::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

void solve(){
    int n;
    std::cin >> n;

    std::vector<int> vec(n);

    for(int i=0;i<n;i++){
        std::cin >> vec[i];
    }
    bool flag = true;

    for(int i=1;i<n;i++){
        int diff = std::abs(vec[i] - vec[i-1]);

        if(diff % 2 != 0) {
            flag = false;
            break;
        }
    }

    if(flag) std::cout << "yes\n";
    else std::cout << "no\n";

}
int main(){
    OnekFast;

    int t;
    std::cin >> t;

    while(t--){
        solve();
    }
}
