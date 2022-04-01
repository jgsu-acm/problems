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
#include <cmath>
const int maxn = 105;
const int maxw = 1e5+5;
bool dp[maxw];
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
        int w;
        cin>>w;
        for(int j=1e5;j>=0;j--)
            dp[j]|=dp[abs(j-w)];
        for(int j=0;j<=1e5-w;j++)
            dp[j]|=dp[j+w];
        dp[w]=true;
    }
    int ans = 0;
    for(int j=1;j<=1e5;j++)
        if(dp[j]) ans++;
    cout<<ans<<endl;
    //======================================
    exit();
}