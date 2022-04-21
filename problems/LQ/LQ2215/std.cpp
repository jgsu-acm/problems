#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <iterator>
#include <algorithm>
const int mod = 1e9+7;
typedef long long ll;
vector<int> a,b;
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
    int n,m;
    cin>>n>>m;
    copy_n(istream_iterator<int>(cin), m, inserter(a, a.begin()));
    cin>>m;
    copy_n(istream_iterator<int>(cin), m, inserter(b, b.begin()));
    b.insert(b.begin(), a.size()-b.size(), 0);
    int i;
    for(i=0;i<a.size();i++)
        if(a[i]>b[i]) break;
    ll ans = a[i]-b[i];
    for(i++;i<a.size();i++)
    {
        int jz = max(2, max(a[i], b[i])+1);
        ans = (ans*jz+a[i]-b[i])%mod;
    }
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
