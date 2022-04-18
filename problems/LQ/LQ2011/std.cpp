#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <cmath>
const int maxn = 1e5+5;
typedef long long ll;
ll a[maxn];
ll mp[maxn][11];
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
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ll tmp = a[i]%k;
        for(int j=0;j<11;j++)
        {
            mp[tmp][j]++;
            tmp = tmp*10%k;
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;i++)
    {
        int len;
        if(a[i]<=2) len = 1;
        else len = ceil(log10(a[i]-1));
        ans += mp[(k-a[i]%k)%k][len];
        ll tmp = a[i]%k;
        while(len--) tmp = tmp*10%k;
        if(tmp%k==(k-a[i]%k)%k) ans--;
    }
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
