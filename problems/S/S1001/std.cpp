#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <vector>
const int maxn = 9+2;
typedef long long ll;
typedef pair<int,int> pii;
vector<pii> v;
ll dp[maxn][1<<maxn][maxn*maxn];
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
    int n,k;
    cin>>n>>k;
    for(int i=0;i<(1<<n);i++)
    {
        if(i&(i<<1)) continue;
        v.emplace_back(i, __builtin_popcount(i));
    }
    for(size_t i=0;i<v.size();i++)
        dp[1][i][v[i].second]=1;
    for(int i=2;i<=n;i++)
    {
        for(size_t j=0;j<v.size();j++)
        {
            for(size_t p=0;p<v.size();p++)
            {
                if(v[j].first&v[p].first||v[j].first&(v[p].first<<1)||(v[j].first<<1)&v[p].first)
                    continue;
                for(size_t q=0;q<=k;q++)
                {
                    if(q+v[j].second>k) break;
                    dp[i][j][q+v[j].second] += dp[i-1][p][q];
                }
            }
        }
    }
    ll ans = 0;
    for(size_t i=0;i<v.size();i++)
        ans += dp[n][i][k];
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}