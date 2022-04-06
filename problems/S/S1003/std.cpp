#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <ranges>
#include <vector>
const int maxn = 2e6+5;
typedef long long ll;
int minp[maxn], power[maxn];
vector<int> pri;
ll qpow(ll a,ll k,ll p)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%p)
        if(k&1) res=res*a%p;
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
    int n,p;
    cin>>n>>p;
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
        }
    }
    ll ans = 1;
    for(int i=2;i<=2*n;i++)
        if(minp[i]==i) ans = ans*qpow(i,power[i],p)%p;
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}