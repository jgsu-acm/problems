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
ll fct[maxn]={0,1}, inv[maxn]={0,1};
inline void inv1()  //? 快速幂 O(nlogn) 求逆元
{
    for(int i=2;i<=1e6;i++) inv[i]=qpow(fct[i], mod-2);
}
ll s[maxn], sv[maxn];
inline void inv2()  //? 线性求任意 n 个数的逆元
{
    int n = 1e6;
    s[1]=1;
    for(int i=2;i<=n;i++) s[i]=s[i-1]*fct[i]%mod;
    sv[n]=qpow(s[n], mod-2);
    for(int i=n-1;i>=1;i--) sv[i]=sv[i+1]*fct[i+1]%mod;
    for(int i=2;i<=n;i++) inv[i]=sv[i]*s[i-1]%mod;
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
    for(int i=2;i<=1e6;i++) fct[i]=fct[i-1]*i%mod;
    inv2();  // 使用线性求任意 n 个数的逆元
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
            else cout<<(c1+a*((1<<(len-1))*(3*len-4)-len+2))%mod<<'\n';
        }
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
