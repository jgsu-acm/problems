#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <cmath>
const int maxn = 1e6+5;
const int mod = 1e9+7;
typedef long long ll;
ll qpow(ll a,ll k)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%mod)
        if(k&1) res=res*a%mod;
    return res;
}
ll fct[maxn], inv[maxn], s[maxn];
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
    fct[1]=inv[1]=1;
    for(int i=2;i<=1e6;i++)
    {
        fct[i]=fct[i-1]*i%mod;
        inv[i]=qpow(fct[i], mod-2);
    }
    s[2]=4;
    for(int i=3;i<=20;i++)
        s[i]=((1<<(i-1))-1+3*(i-1)*(1<<(i-2))%mod+(i-2)*s[i-1]%mod)%mod;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==1) cout<<1<<endl;
        else 
        {
            ll len = (ll)log2(n)+1;
            ll a = fct[n]*inv[len]%mod;
            ll c1 = a*((1<<len)-1)%mod;
            if(n<3*(1<<(len-2))) cout<<c1<<'\n';
            else cout<<(c1+a*s[len])%mod<<'\n';
        }
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
