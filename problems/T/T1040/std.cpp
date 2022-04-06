#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
typedef long long ll;
ll qpow(ll a,ll k,ll p)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%p)
        if(k&1) res=res*a%p;
    return res;
}
ll phi(ll x)
{
    ll res = x;
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            res = res/i*(i-1);
            while(x%i==0) x/=i;
        }
    }
    if(x>1) res = res/x*(x-1);
    return res;
}
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int a,p;
    string b;
    cin>>a>>b>>p;
    ll phip = phi(p);
    ll tmp = 0;
    bool flag = false;
    for(char c : b)
    {
        tmp = tmp*10+c-'0';
        if(tmp>phip)
        {
            tmp %= phip;
            flag = true;
        }
    }
    if(flag) tmp += phip;
    cout<<qpow(a,tmp,p)<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
