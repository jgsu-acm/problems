#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 1e5+5;
typedef long long ll;
int v[maxn];
struct E { int to,next; } Edge[maxn<<1];
int tot,Head[maxn];
inline void AddEdge(int u,int v)
{
    Edge[tot] = {v,Head[u]};
    Head[u] = tot++;
}
int dep[maxn], son[maxn], fa[maxn], siz[maxn];
void dfs1(int u,int f)
{
    siz[u] = 1;
    fa[u] = f;
    dep[u] = dep[f]+1;
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f) continue;
        dfs1(v,u);
        siz[u] += siz[v];
        if(siz[v]>siz[son[u]]) son[u] = v;
    }
}
int tim, dfn[maxn], top[maxn], w[maxn];
void dfs2(int u,int t)
{
    top[u] = t;
    dfn[u] = ++tim;
    w[tim] = v[u];
    if(!son[u]) return;
    dfs2(son[u], t);
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}
struct Node
{
    int l,r;
    ll f,val;
}sgt[maxn<<2];
inline int ls(int k) { return k<<1; }
inline int rs(int k) { return k<<1|1; }
inline void pushup(int k) { sgt[k].val = sgt[ls(k)].val+sgt[rs(k)].val; }
inline void pushdw(int k)
{
    ll f=sgt[k].f; sgt[k].f = 0;
    sgt[ls(k)].f += f;
    sgt[rs(k)].f += f;
    sgt[ls(k)].val += (sgt[ls(k)].r-sgt[ls(k)].l+1)*f;
    sgt[rs(k)].val += (sgt[rs(k)].r-sgt[rs(k)].l+1)*f;
}
void build(int l,int r,int k=1)
{
    sgt[k].l=l, sgt[k].r=r;
    if(l==r)
    {
        sgt[k].val = w[l];
        return;
    }
    int m = (l+r)>>1;
    build(l,m,ls(k));
    build(m+1,r,rs(k));
    pushup(k);
}
void modify_s(int x,int z,int k=1)
{
    int l=sgt[k].l, r=sgt[k].r;
    if(l==r)
    {
        sgt[k].val += z;
        return;
    }
    if(sgt[k].f) pushdw(k);
    int m = (l+r)>>1;
    if(x<=m) modify_s(x,z,ls(k));
    else modify_s(x,z,rs(k));
    pushup(k);
}
void modify_r(int x,int y,int z,int k=1)
{
    int l=sgt[k].l, r=sgt[k].r;
    if(x<=l&&y>=r)
    {
        sgt[k].f += z;
        sgt[k].val += ll(r-l+1)*z;
        return;
    }
    if(sgt[k].f) pushdw(k);
    int m = (l+r)>>1;
    if(x<=m) modify_r(x,y,z,ls(k));
    if(y>m)  modify_r(x,y,z,rs(k));
    pushup(k);
}
ll query(int x,int y,int k=1)
{
    int l=sgt[k].l, r=sgt[k].r;
    if(x<=l&&y>=r) return sgt[k].val;
    if(sgt[k].f) pushdw(k);
    int m = (l+r)>>1;
    ll sum = 0;
    if(x<=m) sum += query(x,y,ls(k));
    if(y>m)  sum += query(x,y,rs(k));
    return sum;
}
void modify_v(int x,int z)
{
    modify_s(dfn[x], z);
}
void modify_t(int x,int z)
{
    modify_r(dfn[x], dfn[x]+siz[x]-1, z);
}
ll query_p(int x,int y)
{
    ll sum = 0;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        sum += query(dfn[top[x]], dfn[x]);
        x = fa[top[x]];
    }
    if(dep[x]>dep[y])
        swap(x,y);
    sum += query(dfn[x], dfn[y]);
    return sum;
}
#include <cstring>
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
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        AddEdge(u,v);
        AddEdge(v,u);
    }
    dfs1(1,0);
    dfs2(1,1);
    build(1,n);
    while(m--)
    {
        int opt,x,y;
        cin>>opt>>x;
        switch(opt)
        {
        case 1:
            cin>>y;
            modify_v(x,y);
            break;
        case 2:
            cin>>y;
            modify_t(x,y);
            break;
        case 3:
            cout<<query_p(1,x)<<'\n';
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