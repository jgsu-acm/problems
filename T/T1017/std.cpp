#include <iostream>
#include <ctime>
using namespace std;
clock_t c1;
inline void exit()
{
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    exit(0);
}
//==========================================
const int maxn = 15;
typedef long long ll;
ll a[maxn], n[maxn], c[maxn];
void exgcd(ll a,ll b,ll& x, ll& y)
{
    if(!b)
    {
        x=1,y=0;
        return;
    }
    exgcd(b,a%b,y,x);
    y-=a/b*x;
}
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    c1 = clock();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int k;
    cin>>k;
    ll N = 1;
    for(int i=0;i<k;i++)
    {
        cin>>n[i]>>a[i];
        N *= n[i];
    }
    for(int i=0;i<k;i++)
    {
        ll m = N / n[i];
        ll x,y;
        exgcd(m, n[i], x, y);
        x = (x+n[i])%n[i];
        c[i]=m*x;
    }
    ll ans = 0;
    for(int i=0;i<k;i++)
        ans = (ans + a[i]*c[i])%N;
    cout<<ans<<endl;
    //======================================
    exit();
}