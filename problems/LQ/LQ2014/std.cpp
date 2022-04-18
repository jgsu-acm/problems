#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <numeric>
const int maxn = 1e4+5;
typedef long long ll;
int fa[maxn];
ll a[maxn], val[maxn];
int find(int x)
{
    if(fa[x]==x) return x;
    int rt = find(fa[x]);
    val[x] += val[fa[x]];
    return fa[x] = rt;
}
void merge(int x,int y)
{
    int fx=find(x), fy=find(y);
    if(fx==fy) return;
    fa[fx] = fy;
    val[fx] = a[fx]-a[fy];
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
    int n,m;
    cin>>n>>m;
    iota(fa+1, fa+1+n, 1);
    while(m--)
    {
        int opt,x,y;
        cin>>opt>>x>>y;
        if(opt==1) merge(x,y);
        else a[find(x)] += y;
    }
    for(int i=1;i<=n;i++) cout<<a[find(i)]+val[i]<<' ';
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
