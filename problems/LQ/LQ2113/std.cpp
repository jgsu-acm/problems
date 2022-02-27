#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
//==========================================
#include <string>
#include <algorithm>
#include <cstring>
const int maxn = 5005;
const int mod = 1e9+7;
int lb[maxn];
int dp[maxn][maxn],pre[maxn][maxn];
int calc(string& s)
{
    int l=0,r=0,cnt=0,n=0,x=0;
    for(char c : s)
    {
        if(c==40) l++, cnt++;
        else lb[++n]=max(++r-l, 0), cnt--;
        if(cnt<0) x++, cnt++;
    }
    memset(dp, 0, sizeof(dp));
    memset(pre, 0, sizeof(pre));
    for(int i=lb[1];i<=x;i++) dp[1][i]=1, pre[1][i]=i-lb[1]+1;
    for(int i=2;i<=n;i++)
    {
        for(int j=lb[i];j<=x;j++)
        {
            dp[i][j]=pre[i-1][j];
            pre[i][j]=j?(pre[i][j-1]+dp[i][j])%mod:dp[i][j];
        }
    }
    return max(1, dp[n][x]);
}
signed main(signed argc, char const *argv[])
{
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    //======================================
    string s;
    cin>>s;
    long long ans = calc(s);
    reverse(s.begin(), s.end());
    transform(s.begin(), s.end(), s.begin(), [](char c)->char{ return c^1; });
    cout<<ans*calc(s)%mod<<endl;
    //======================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}