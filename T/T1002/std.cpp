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
const int maxn = 1e5+5;
int a[maxn];
struct Node
{
    int l,r,val;
}sgt[maxn<<2];
inline int ls(int k) { return k<<1; }
inline int rs(int k) { return k<<1|1; }
inline void pushup(int k) { sgt[k].val=sgt[ls(k)].val+sgt[rs(k)].val; }
void build(int l,int r,int k=1)
{
    sgt[k].l=l, sgt[k].r=r;
    if(l==r)
    {
        sgt[k].val=a[l];
        return;
    }
    int m = (l+r)>>1;
    build(l,m,ls(k));
    build(m+1,r,rs(k));
    pushup(k);
}
void modify_single(int p,int z,int k=1)
{
    int l=sgt[k].l, r=sgt[k].r;
    if(l==r)
    {
        sgt[k].val+=z;
        return;
    }
    int m = (l+r)>>1;
    if(p<=m) modify_single(p, z, ls(k));
    else modify_single(p, z, rs(k));
    pushup(k);
}
int query_single(int p, int k=1)
{
    int l=sgt[k].l, r=sgt[k].r;
    if(l==r) return sgt[k].val;
    int m = (l+r)>>1;
    if(p<=m) return query_single(p, ls(k));
    else return query_single(p, rs(k));
}
int query(int x,int y,int k=1)
{
    int l=sgt[k].l, r=sgt[k].r;
    if(x<=l&&y>=r) return sgt[k].val;
    int m = (l+r)>>1;
    int sum = 0;
    if(x<=m) sum+=query(x,y,ls(k));
    if(y>m) sum+=query(x,y,rs(k));
    return sum;
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
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,n);
    while(m--)
    {
        int opt,x,y;
        cin>>opt;
        switch(opt)
        {
        case 1:
            cin>>x;
            cout<<query_single(x)<<endl;
            break;
        case 2:
            cin>>x>>y;
            modify_single(x,y);
            break;
        case 3:
            cin>>x>>y;
            cout<<query(x,y)<<endl;
            break;
        }
    }
    //======================================
    exit();
}