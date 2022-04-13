#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <algorithm>
const int maxn = 22;
typedef long long ll;
int G[maxn][maxn];
ll dp[1<<maxn][maxn];
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
    int n = 21;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(__gcd(i,j)==1) G[i][j] = G[j][i] = 1;
    dp[1][1] = 1;
    for(int i=1;i<(1<<n);i++)
        for(int j=1;j<=n;j++)
            if(i&(1<<(j-1)))
                for(int k=1;k<=n;k++)
                    if(!(i&(1<<(k-1)))&&G[j][k])
                        dp[i+(1<<(k-1))][k] += dp[i][j];
    ll sum = 0;
    for(int i=1;i<=n;i++)
        if(G[1][i])
            sum += dp[(1<<n)-1][i];
    cout<<sum<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
