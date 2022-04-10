#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cstring>
const int maxn = 1e5+5;
int p;
struct E { int to,next; } Edge[maxn<<1];
int Head[maxn], tot;
inline void AddEdge(int u,int v)
{
    Edge[tot]={v,Head[u]};
    Head[u]=tot++;
}
int v[maxn];
int siz[maxn], son[maxn], dep[maxn], fa[maxn];
void dfs1(int u,int f)
{
    int maxsize = -1;
    siz[u]=1;
    fa[u] = f;
    dep[u] = dep[f]+1;
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f) continue;
        dfs1(v,u);
        siz[u] += siz[v];
        if(siz[v]>maxsize)
        {
            son[u] = v;
            maxsize = siz[v];
        }
    }
}
int tim, dfn[maxn], top[maxn], w[maxn];
void dfs2(int u,int t)
{
    dfn[u] = ++tim;
    top[u] = t;
    w[tim] = v[u];
    if(!son[u]) return;
    dfs2(son[u],t);
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}
typedef long long ll;
struct Node
{
    int l,r;
    ll f,val;
}sgt[maxn<<2];
inline int ls(int k) { return k<<1; }
inline int rs(int k) { return k<<1|1; }
inline void pushup(int k) { sgt[k].val = (sgt[ls(k)].val+sgt[rs(k)].val)%p; }
inline void pushdw(int k)
{
    ll f=sgt[k].f; sgt[k].f=0;
    sgt[ls(k)].f = (sgt[ls(k)].f + f)%p;
    sgt[rs(k)].f = (sgt[rs(k)].f + f)%p;
    sgt[ls(k)].val = (sgt[ls(k)].val+(sgt[ls(k)].r-sgt[ls(k)].l+1)*f)%p;
    sgt[rs(k)].val = (sgt[rs(k)].val+(sgt[rs(k)].r-sgt[rs(k)].l+1)*f)%p;
}
void build(int l,int r,int k=1)
{
    sgt[k].l=l, sgt[k].r=r;
    if(l==r)
    {
        sgt[k].val = w[l]%p;
        return;
    }
    int m = (l+r)>>1;
    build(l,m,ls(k));
    build(m+1,r,rs(k));
    pushup(k);
}
void modify(int x,int y,ll z,int k=1)
{
    z %= p;
    int l=sgt[k].l, r=sgt[k].r;
    if(x<=l&&y>=r)
    {
        sgt[k].f = (sgt[k].f+z)%p;
        sgt[k].val = (sgt[k].val+(r-l+1)*z)%p;
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
    int l=sgt[k].l, r=sgt[k].r;
    if(x<=l&&y>=r) return sgt[k].val%p;
    if(sgt[k].f) pushdw(k);
    int m = (l+r)>>1;
    ll sum = 0;
    if(x<=m) sum = (sum+query(x,y,ls(k)))%p;
    if(y>m)  sum = (sum+query(x,y,rs(k)))%p;
    return sum;
}
void mpath(int x,int y,ll z)
{
    z %= p;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        modify(dfn[top[x]],dfn[x],z);
        x = fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    modify(dfn[x],dfn[y],z);
}
ll qpath(int x,int y)
{
    ll sum = 0;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        sum = (sum+query(dfn[top[x]],dfn[x]))%p;
        x = fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    sum = (sum+query(dfn[x],dfn[y]))%p;
    return sum;
}
void mson(int x,ll z)
{
    modify(dfn[x], dfn[x]+siz[x]-1, z);
}
ll qson(int x)
{
    return query(dfn[x], dfn[x]+siz[x]-1);
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
    memset(Head,-1,sizeof(Head));
    int n,m,r;
    cin>>n>>m>>r>>p;
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        AddEdge(u,v);
        AddEdge(v,u);
    }
    dfs1(r,0);
    dfs2(r,r);
    build(1,n);
    while(m--)
    {
        int opt,x,y,z;
        cin>>opt;
        switch(opt)
        {
        case 1:
            cin>>x>>y>>z;
            mpath(x,y,z);
            break;
        case 2:
            cin>>x>>y;
            cout<<qpath(x,y)<<'\n';
            break;
        case 3:
            cin>>x>>y;
            mson(x,y);
            break;
        case 4:
            cin>>x;
            cout<<qson(x)<<'\n';
            break;
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
