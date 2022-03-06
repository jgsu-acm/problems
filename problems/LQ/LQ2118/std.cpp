#include <iostream>
#include <ctime>
using namespace std;
//==========================================
const int maxn = 2025;
typedef long long ll;
ll dp[maxn][maxn];
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
    //* dp[i][j] i 分成 j 个正整数之和的方案数
    //* dp[i][1] = 1
    //* dp[i][j] = \sum_{k=1}^{i-1} dp[k][j-1]
    //* dp[n][m]
    int n=2021, m=5;
    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=min(i,m);j++)
        {
            if(j==1) dp[i][j]=1;
            else 
            {
                ll sum = 0;
                for(int k=1;k<i;k++)
                    sum += dp[k][j-1];
                dp[i][j]=sum;
            }
        }
    }
    cout<<dp[n][m]<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
