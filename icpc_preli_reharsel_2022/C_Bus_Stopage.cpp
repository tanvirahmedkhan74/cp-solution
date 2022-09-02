#include <bits/stdc++.h>

typedef long long int ll;

#define digPs(n) std::fixed << std::setprecision(n)

#define SheiFast std::ios_base::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);

// bool is_valid_triangle(int a, int b, int c) {
//     vector<int> sides = {a, b, c};

//     sort(sides.begin(), sides.end());
//     return sides[0] + sides[1] >= sides[2];
// }

int main(){
    SheiFast;
    
    int t;
    std::cin >> t;

    while(t--){
        ll n;
        std::cin >> n;

        ll in, b, c;

        in = 1;
        int cnt = 0;

        if(n % 2 == 0){
            b = (n - 1) / 2;
            c = b + 1;
        }else b = c = (n-1) / 2;
        
        while(b > 0){
            ll t_b = b;
            ll t_c = c;

            while(t_b <= t_c){
                t_b++;
                t_c--;

                cnt++;
            }

            in++;
            b--;

            if((in + b + c) != n) break; 
        }

        std::cout << cnt << "\n";
    }
}