#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <iomanip>
const int maxn = 1e5+5;
const double eps = 1e-8;
int n;
double a[maxn], b[maxn];
bool check(double m)
{
    for(int i=1;i<=n;i++)
        if(a[i]-m*b[i]>0)
            return true;
    return false;
}
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    double l=0, r=1e9;
    while(r-l>eps)
    {
        double m = (l+r)/2;
        if(check(m)) l = m;
        else r = m;
    }
    cout<<fixed<<setprecision(6)<<l<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
