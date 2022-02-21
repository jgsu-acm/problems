#include <iostream>
#include <ctime>
using namespace std;
clock_t c1;
inline void exit()
{
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    exit(0);
}
//==========================================
const int maxn = 205;
const int INF = 0x3f3f3f3f;
int a[maxn], pre[maxn];
int dp1[maxn][maxn], dp2[maxn][maxn];
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    c1 = clock();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i];
    }
    for(int i=1;i<2*n;i++)
        pre[i]=pre[i-1]+a[i];
    for(int l=1;l<n;l++)
    {
        for(int i=1,j=i+l;j<2*n;i++,j++)
        {
            dp1[i][j]=-INF;
            dp2[i][j]=INF;
            for(int k=i;k<j;k++)
            {
                dp1[i][j]=max(dp1[i][j], dp1[i][k]+dp1[k+1][j]+pre[j]-pre[i-1]);
                dp2[i][j]=min(dp2[i][j], dp2[i][k]+dp2[k+1][j]+pre[j]-pre[i-1]);
            }
        }
    }
    int mx=-INF, mn=INF;
    for(int i=1;i<=n;i++)
    {
        mx=max(mx, dp1[i][i+n-1]);
        mn=min(mn, dp2[i][i+n-1]);
    }
    cout<<mn<<endl<<mx<<endl;
    //======================================
    exit();
}
