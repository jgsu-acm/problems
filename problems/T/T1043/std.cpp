#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 1e7+5;
typedef long long ll;
int a[maxn];
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
        cin>>a[i];
    int l = 1;
    ll sum = 0;
    ll cnt = 0;
    for(int r=1;r<=n;r++)
    {
        sum += a[r];
        while(l<=r&&sum>k) sum -= a[l++];
        cnt += r-l+1;
    }
    cout<<cnt<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
