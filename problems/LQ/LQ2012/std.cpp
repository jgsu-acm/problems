#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
typedef long long ll;
vector<ll> v;
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
    int n;
    ll k;
    cin>>n>>k;
    copy_n(istream_iterator<int>(cin), n, inserter(v,v.begin()));
    sort(v.begin(), v.end());
    ll ans = 0;
    for(auto it=v.begin();it!=v.end();++it)
    {
        ll p = *it==1?10:10*ceil(log10(*it));
        auto t = upper_bound(v.begin(), v.end(), k/p-(k%p<*it));
        if(t>it) ans--;
        ans += t-v.begin();
    }
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
