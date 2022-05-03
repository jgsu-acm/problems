#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
const int maxn = 1e3+5;
const int maxw = 5e3+5;
const double eps = 1e-8;
int n,W;
int a[maxn], b[maxn];
double dp[maxw];
bool check(double m)
{
    fill(dp+1, dp+1+W, -1e9);
    for(int i=1;i<=n;i++)
    {
        for(int j=W;j>=0;j--)
        {
            int t = min(W, j+b[i]);
            dp[t] = max(dp[t], dp[j]+a[i]-m*b[i]);
        }
    }
    return dp[W]>0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>W;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    double l=0, r=1e4;
    while(r-l>eps)
    {
        double mid = (l+r)/2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout<<fixed<<setprecision(6)<<l<<endl;
    return 0;
}
