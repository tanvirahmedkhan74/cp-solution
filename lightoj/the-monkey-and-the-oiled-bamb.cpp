#include<bits/stdc++.h>

typedef long long int ll;

#define SheiFast std::ios_base::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);

int binarySearchLower(const std::vector<ll>& vec, ll key){
    int l = 0, r = vec.size() - 1;

    int ans = -1;

    while(l <= r){
        int mid = (l + r) / 2;

        if(vec[mid] >= key){
            ans = mid;
            r = mid - 1;
        }else l = mid + 1;
    }

    return ans;
}

int main(){
    SheiFast;

    int t;
    std::cin >> t;
    
    int cs = 0;
    while(t--){
        int n;
        std::cin >> n;

        std::vector<ll> ladd(n), diff;

        for(int i=0;i<n;i++){
            std::cin >> ladd[i];
        }

        diff.push_back(ladd[0]);

        ll maxi = ladd[0];

        for(int i=1;i<n;i++){
            diff.push_back(ladd[i] - ladd[i-1]);
            maxi = std::max(maxi, ladd[i] - ladd[i-1]);
        }


        int cur = maxi;

        for(int i=0;i<n;i++){
           if(diff[i] > cur){
                maxi++;
                break;
           }else if(diff[i] == cur) cur--;
        }

        std::cout << "Case " << ++cs << ": " << maxi << "\n";
    }
}
