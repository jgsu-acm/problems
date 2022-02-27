#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
//==========================================
const int maxn = 1e5 + 5;
const int mod = 998244353;
typedef long long ll;
ll a[maxn];
struct Node
{
    int l,r;
    ll val,f;
}sgt[maxn<<2];
inline int ls(int k) { return k<<1; }
inline int rs(int k) { return k<<1|1; }
inline void pushup(int k) { sgt[k].val=(sgt[ls(k)].val+sgt[rs(k)].val)%mod; }
inline void pushdw(int k)
{
    ll f=sgt[k].f; sgt[k].f=0;
    sgt[ls(k)].f=(sgt[ls(k)].f+f)%mod; sgt[rs(k)].f=(sgt[rs(k)].f+f)%mod;
    sgt[ls(k)].val+=(sgt[ls(k)].r-sgt[ls(k)].l+1)*f%mod;
    sgt[rs(k)].val+=(sgt[rs(k)].r-sgt[rs(k)].l+1)*f%mod;
    sgt[ls(k)].val%=mod;
    sgt[rs(k)].val%=mod;
}
void build(int l,int r,int k=1)
{
    sgt[k].l=l, sgt[k].r=r;
    if(l==r)
    {
        sgt[k].val=a[l]%mod;
        return;
    }
    int m = (l+r)>>1;
    build(l, m, ls(k));
    build(m+1, r, rs(k));
    pushup(k);
}
void modify(int x,int y,int z,int k=1)
{
    ll l=sgt[k].l, r=sgt[k].r;
    if(x<=l&&y>=r)
    {
        sgt[k].f=(sgt[k].f+z)%mod;
        sgt[k].val+=(r-l+1)*z%mod;
        return;
    }
    if(sgt[k].f) pushdw(k);
    int m = (l+r)>>1;
    if(x<=m) modify(x,y,z,ls(k));
    if(y>m)  modify(x,y,z,rs(k));
    pushup(k);
}
ll query(int x,int y,int k=1)
{
    ll l=sgt[k].l, r=sgt[k].r;
    if(x<=l&&y>=r) return sgt[k].val%mod;
    if(sgt[k].f) pushdw(k);
    int m = (l+r)>>1;
    ll sum = 0;
    if(x<=m) sum+=query(x,y,ls(k));
    if(y>m)  sum+=query(x,y,rs(k));
    return sum%mod;
}
signed main(signed argc, char const *argv[])
{
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    //======================================
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,n);
    while(m--)
    {
        ll opt,x,y,z;
        cin>>opt>>x>>y;
        if(opt==1)
        {
            cin>>z;
            modify(x,y,z);
        }
        else cout<<query(x,y)<<endl;
    }
    //======================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}