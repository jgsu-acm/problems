#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5+5;
int a[maxn], b[maxn], c[maxn];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        for(int i=0;i<n;i++) c[i] = a[i]-b[i];
        sort(c, c+n);
        long long ans = 0;
        for(int i=0;i<n;i++) ans += b[i];
        for(int i=0;i<k;i++) ans += c[i];
        cout<<ans<<'\n';
    }
    return 0;
}
