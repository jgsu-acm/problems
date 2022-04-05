#include <iostream>
#include <ctime>
using namespace std;
//==========================================
const int maxn = 35;
int dp[maxn][maxn];
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
    int n,m;
    cin>>n>>m;
    dp[1][1] = 1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!(i==1&&j==1)&&(i%2||j%2))
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
    cout<<dp[n][m]<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
