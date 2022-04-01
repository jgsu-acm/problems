#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <numeric>
const int maxn = 20210511;
typedef long long ll;
ll dp[maxn] = {0, 1};
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    clock_t c1 = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n = 20210509;
    for(int i=1;i<=n;i++)
        for(int j=2;j<=n/i;j++)
            dp[i*j] += dp[i];
    cout<<accumulate(dp+1, dp+1+n, 0LL)<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
