#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <ranges>
#include <vector>
const int maxn = 1015;
const int mod = 2020;
namespace solution1  // 填表法 DP
{
    int dp[maxn][maxn];
    int calc(int n)
    {
        for(int i=1;i<=n;i++) dp[i][0] = 1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
        return dp[n][n];
    }
}
namespace solution2  // 刷表法 DP
{
    int dp[maxn][maxn];
    int calc(int n)
    {
        dp[0][0]=1;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i<n) dp[i+1][j] = (dp[i+1][j]+dp[i][j])%mod;
                if(j<n&&i>j) dp[i][j+1] = (dp[i][j+1]+dp[i][j])%mod;
            }
        }
        return dp[n][n];
    }
}
namespace solution3  // 杨表勾长公式（卡特兰数）解法
{
    typedef long long ll;
    int minp[maxn<<1], power[maxn<<1];
    vector<int> pri;
    ll qpow(ll a,ll k,ll p)
    {
        ll res = 1;
        for(;k;k>>=1,a=a*a%p)
            if(k&1) res=res*a%p;
        return res;
    }
    int calc(int n)
    {
        for(int i : views::iota(2,2*n+1))
        {
            if(!minp[i])
            {
                pri.push_back(i);
                minp[i] = i;
            }
            for(int j : pri)
            {
                if((ll)i*j>2*n) break;
                minp[i*j] = j;
                if(i%j==0) break;
            }
        }
        for(int i=n+2;i<=2*n;i++) power[i] = 1;
        for(int i=2;i<=n;i++) power[i] = -1;
        for(int i=2*n;i>=2;i--)
        {
            if(minp[i]!=i)
            {
                power[minp[i]] += power[i];
                power[i/minp[i]] += power[i];
                power[i] = 0;
            }
        }
        ll ans = 1;
        for(int i=2;i<=2*n;i++)
            if(minp[i]==i) ans = ans*qpow(i,power[i],mod)%mod;
        return ans;
    }
}
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
    int n = 1010;
    cout<<"Method 1:"<<solution1::calc(n)<<endl;
    cout<<"Method 2:"<<solution2::calc(n)<<endl;
    cout<<"Method 3:"<<solution3::calc(n)<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
