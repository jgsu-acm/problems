#include <iostream>
#include <ctime>
using namespace std;
//==========================================
typedef long long ll;
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
    ll n,k;
    cin>>n>>k;
    ll sum = n*k;
    for(int l=1,r;l<=n;l=r+1)
    {
        r = k>l?min(k/(k/l), n):n;
        sum -= (r-l+1)*(k/l)*(l+r)/2;
    }
    cout<<sum<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
