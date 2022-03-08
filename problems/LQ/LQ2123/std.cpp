#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <map>
#include <algorithm>
typedef long long ll;
map<ll, int> fac(ll n)
{
    map<ll, int> ret;
    for(ll i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            n/=i;
            ++ret[i];
        }
    }
    if(n!=1) ++ret[n];
    return ret;
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
    ll n;
    cin>>n;
    auto facts = fac(n);
    ll mul = 1;
    for(auto [x,y] : facts)
        if(y%2) mul *= x;
    cout<<mul<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
