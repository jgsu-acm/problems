#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <iomanip>
#include <algorithm>
const int maxn = 1e5+5;
const double eps = 1e-6;
int n;
int a[maxn], b[maxn];
double c[maxn];
bool check(double m)
{
    double sum = 0;
    for(int i=1;i<=n;i++) c[i] = a[i]-m*b[i];
    sort(c+1, c+1+n, greater<int>());
    for(int i=1;i<=5;i++) sum += c[i];
    return sum>0;
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
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    double l=0, r=5e3;
    while(r-l>eps)
    {
        double mid = (l+r)/2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout<<fixed<<setprecision(6)<<l<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
