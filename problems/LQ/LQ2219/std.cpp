#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 105;
const int mod = 1e9+7;
typedef long long ll;
ll dp[maxn<<1][maxn][maxn];
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n,m;
    cin>>n>>m;
    dp[0][0][2] = 1;
    for(int i=0;i<n+m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            for(int k=0;k<m+1;k++)
            {
                if(j<n) (dp[i+1][j+1][min(k*2,m+1)] += dp[i][j][k]) %= mod;
                if(k>=0) (dp[i+1][j][k-1] += dp[i][j][k]) %= mod;
            }
        }
    }
    cout<<dp[n+m-1][n][1]<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
