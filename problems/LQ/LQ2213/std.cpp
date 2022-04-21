#include <iostream>
#include <chrono>
using namespace std;
//==========================================
typedef long long ll;
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
    ll a,b,n;
    cin>>a>>b>>n;
    ll t = 5*a+2*b;
    ll ans = n/t*7;
    n %= t;
    if(n<=5*a) ans += n/a+(n%a?1:0);
    else
    {
        ans += 5;
        n -= 5*a;
        ans += n/b+(n%b?1:0);
    }
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
