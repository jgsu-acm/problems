#include <iostream>
#include <chrono>
using namespace std;
//==========================================
typedef long long ll;
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
    int q;
    cin>>q;
    while(q--)
    {
        ll x;
        cin>>x;
        cout<<phi(x)<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
