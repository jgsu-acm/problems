#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 998244353;
ll qpow(ll a, ll b, ll p)
{
    ll ret = 1;
    for(;b;b>>=1,a=a*a%p)
        if(b&1) ret = ret*a%p;
    return ret;
}
int main()
{
    string s1, s2;
    cin>>s1>>s2;
    ll a=0, b=0;
    for(auto c : s1)
    {
        a*=10;
        a+=c-'0';
        a%=mod;
    }
    for(auto c : s2)
    {
        b*=10;
        b+=c-'0';
        b%=mod;
    }
    if(!b) cout<<"invalid\n";
    else cout<<a*qpow(b, mod-2, mod)%mod<<'\n';
    return 0;
}