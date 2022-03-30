#include <iostream>
#include <ctime>
using namespace std;
//==========================================
const int maxn = 1e5+5;
typedef long long ll;
ll fac[maxn];
ll qpow(ll a,ll k,ll p)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%p)
        if(k&1) res=res*a%p;
    return res;
}
ll C(ll n,ll m,ll p)
{
    return n>=m?fac[n]*qpow(fac[m],p-2,p)%p*qpow(fac[n-m],p-2,p)%p:0;
}
ll lucas(ll n,ll m,ll p)
{
    return m?lucas(n/p, m/p, p)*C(n%p, m%p, p)%p:1;
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
    fac[0]=1;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,p;
        cin>>n>>m>>p;
        for(int i=1;i<p;i++) fac[i]=fac[i-1]*i%p;
        cout<<lucas(n,m,p)<<'\n';
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}