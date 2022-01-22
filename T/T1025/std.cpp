#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5+5;
int map[MAXN],p[MAXN],d[MAXN];
int main(int argc, char const* argv[])
{
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        map[x] = i;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        p[i] = map[x];
    }
    d[1] = p[1];
    int len = 1;
    for(int i=2;i<=n;i++)
    {
        if(p[i]>d[len]) d[++len] = p[i];
        else *upper_bound(d+1,d+1+len,p[i]) = p[i];
    }
    cout<<len<<endl;
    return 0;
}