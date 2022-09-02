#include <bits/stdc++.h>
 
typedef long long int ll;
 
#define error 10e-8
#define digPs(n) std::fixed << std::setprecision(n)
#define OnekFast std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
 
 
int main(){
    OnekFast;
 
    int t;
    std::cin >> t;

    std::unordered_map<std::string, double> curr;
 
    while(t--){
        int c, n;
 
        std::cin >> c >> n;
        
        curr.clear();

        std::string temp;
        double val;
 
        for(int i=0;i<c;i++){
            std::cin >> temp >> val;
 
            curr[temp] = val;
        }
 
        double ans = 0;
 
        for(int i=0;i<n;i++){
            std::cin >> val >> temp;
 
            if(temp == "JD") ans += val;
 
            ans += (curr[temp] * val);
        }
 
       std::cout << std::fixed << std::setprecision(6) << ans << "\n";
    }
}
