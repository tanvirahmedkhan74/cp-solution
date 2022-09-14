#include <bits/stdc++.h>

typedef long long int ll;

#define digPos(n) std::fixed << std::setprecision(n)

#define SheiFast std::ios_base::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);

#define PI std::acos(-1.0)

#define error 1e-10


bool checkPie(const std::vector<double>& vec, int s, int f, double mid)
{
    int cnt = 0;

    for(int i=0;i<s;i++){
        cnt += (int)(vec[i] / mid);

        if(cnt >= f) break;
    }
    return (cnt - f >= 0);
}

int main()
{
    SheiFast;

    int t;
    std::cin >> t;

    while (t--)
    {
        int n, f;
        std::cin >> n >> f;

        std::vector<int> vec(n);

        for (int &a : vec)
        {
            std::cin >> a;
        }

        std::vector<double> pie(n);

        for (int i = 0; i < n; i++)
        {
            pie[i] = PI * vec[i] * vec[i];
        }

        double l = 0, r = 1000000000;

        double ans = 0;

        // while (l + error < r) --> TLE if search like this
        for(int i=0;i<64;i++)
        {
            double mid = l + (r - l) / 2.0;

            if(checkPie(pie, n, f + 1, mid)){
                ans = mid;
                l = mid;
            }else r = mid;
        }

        std::cout << digPos(4) << ans + error << "\n";
    }
}
