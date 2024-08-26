#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
ll qpow(ll a,ll k)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%mod) if(k&1) res = res*a%mod;
    return res;
}
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<ll> s(n+1), sv(n+1), res(n);
    s[0] = 1;
    for(int i=1;i<=n;i++) s[i] = s[i-1]*a[i-1]%mod;
    sv[n] = qpow(s[n], mod-2);
    for(int i=n;i>=1;i--) sv[i-1] = sv[i]*a[i-1]%mod;
    for(int i=0;i<n;i++) res[i] = sv[i+1]*s[i]%mod;
    cout<<accumulate(res.begin(), res.end(), 0ll)<<'\n';
    return 0;
}
