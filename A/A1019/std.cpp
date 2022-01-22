#include <iostream>
using namespace std;
const int maxn = 1e6+5;
const int mod = 998244353;
typedef long long ll;
int a[maxn];
ll qpow(ll a,ll b,ll p)
{
    ll ret = 1;
    for(;b;b>>=1,a=a*a%p)
        if(b&1) ret=ret*a%p;
    return ret;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    ll p=1, q=0;
    for(int i=n-1;i>=0;i--)
    {
        swap(p,q);
        p = (p+a[i]*q)%mod;
    }
    cout<<p*qpow(q, mod-2, mod)%mod<<endl;
    return 0;
}