#include <iostream>
#include <ctime>
using namespace std;
//==========================================
const int maxn = (1<<6)+5;
const int mod = 1e9+7;
int pc[maxn];
int dp[105][maxn][maxn][25];
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
    int n,m,k;
    cin>>n>>m>>k;
    // dp[i][p][q][j] 当前放到第 i 行，放法为 p，上一行放法为 q，已经放了 j 个马的方案数
    // dp[1][?][0][popcount(?)] = 1
    // dp[i][p][q][j] = Σdp[i-1][q][a=与p不冲突][j-popcount(a)]
    // dp[m][?][?][k]
    for(int i=0;i<(1<<n);i++)
    {
        pc[i]=__builtin_popcount(i);
        if(pc[i]>k) continue;
        dp[1][i][0][pc[i]]=1;
    }
    for(int i=2;i<=m;i++)
    {
        for(int p=0;p<(1<<n);p++)
        {
            for(int q=0;q<(1<<n);q++)
            {
                if(p<<2&q || p>>2&q) continue;
                for(int a=0;a<(1<<n);a++)
                {
                    if(p<<1&a || p>>1&a) continue;
                    for(int j=0;j<=k-pc[p];j++)
                    {
                        dp[i][p][q][j+pc[p]] += dp[i-1][q][a][j];
                        dp[i][p][q][j+pc[p]] %= mod;
                    }
                }
            }
        }
    }
    int sum = 0;
    for(int p=0;p<(1<<n);p++)
        for(int q=0;q<(1<<n);q++)
            sum = (sum + dp[m][p][q][k]) % mod;
    cout<<sum<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
