#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 505;
typedef long long ll;
int a[maxn][maxn];
ll pre[maxn][maxn];
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
    ll k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            pre[i][j] = pre[i][j-1]+a[i][j];
        }
    }
    ll cnt = 0;
    for(int l=1;l<=m;l++)
    {
        for(int r=l;r<=m;r++)
        {
            int t = 1;
            ll sum = 0;
            for(int b=1;b<=n;b++)
            {
                sum += pre[b][r]-pre[b][l-1];
                while(t<=b&&sum>k)
                {
                    sum -= pre[t][r]-pre[t][l-1];
                    t++;
                }
                cnt += b-t+1;
            }
        }
    }
    cout<<cnt<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
