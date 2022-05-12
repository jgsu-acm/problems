#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 1e6+5;
int a[maxn];
struct Node { int l,r,val; } hjt[maxn*25];
int cnt, root[maxn];
void build(int l,int r,int& k)
{
    k = ++cnt;
    if(l==r)
    {
        hjt[k].val = a[l];
        return;
    }
    int m = (l+r)>>1;
    build(l,m,hjt[k].l);
    build(m+1,r,hjt[k].r);
}
void modify(int l,int r,int pre,int &k,int p,int z)
{
    k = ++cnt;
    hjt[k] = hjt[pre];
    if(l==r)
    {
        hjt[k].val = z;
        return;
    }
    int m = (l+r)>>1;
    if(p<=m) modify(l,m,hjt[pre].l,hjt[k].l,p,z);
    else modify(m+1,r,hjt[pre].r,hjt[k].r,p,z);
}
int query(int l,int r,int k,int p)
{
    if(l==r) return hjt[k].val;
    int m = (l+r)>>1;
    if(p<=m) return query(l,m,hjt[k].l,p);
    else return query(m+1,r,hjt[k].r,p);
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
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,n,root[0]);
    for(int i=1;i<=m;i++)
    {
        int opt,x,y,z;
        cin>>z>>opt>>x;
        if(opt==1)
        {
            cin>>y;
            modify(1,n,root[z],root[i],x,y);
        }
        else
        {
            cout<<query(1,n,root[z],x)<<'\n';
            root[i] = root[z];
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
