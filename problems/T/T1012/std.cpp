#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <cmath>
const int maxn = 1e5+5;
int st[20][maxn];
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
    for(int i=1;i<=n;i++)
        cin>>st[0][i];
    for(int i=1;(1<<i)<=n;i++)
        for(int j=1;j+(1<<i)-1<=n;j++)
            st[i][j]=max(st[i-1][j], st[i-1][j+(1<<(i-1))]);
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        int k = log2(r-l+1);
        cout<<max(st[k][l], st[k][r-(1<<k)+1])<<'\n';
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}