#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 1e5+5;
struct E { int to,next; } Edge[maxn<<1];
int tot,Head[maxn];
inline void AddEdge(int u,int v)
{
    Edge[tot] = {v,Head[u]};
    Head[u] = tot++;
}
int son[maxn], fa[maxn], dep[maxn], siz[maxn];
void dfs1(int u,int f)
{
    fa[u] = f;
    dep[u] = dep[f]+1;
    siz[u] = 1;
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f) continue;
        dfs1(v,u);
        siz[u] += siz[v];
        if(siz[v]>siz[son[u]]) son[u] = v;
    }
}
int tim, dfn[maxn], nfd[maxn], top[maxn];
void dfs2(int u,int t)
{
    dfn[u] = ++tim;
    nfd[tim] = u;
    top[u] = t;
    if(!son[u]) return;
    dfs2(son[u], t);
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}
struct Node { int l,r,val; } sgt[maxn<<2];
inline int ls(int k) { return k<<1; }
inline int rs(int k) { return k<<1|1; }
inline void pushup(int k) { sgt[k].val = max(sgt[ls(k)].val, sgt[rs(k)].val); }
void build(int l,int r,int k=1)
{
    sgt[k].l=l, sgt[k].r=r;
    if(l==r) return;
    int m = (l+r)>>1;
    build(l,m,ls(k));
    build(m+1,r,rs(k));
    pushup(k);
}
void modify(int x,int z,int k=1)
{
    int l=sgt[k].l, r=sgt[k].r;
    if(l==r)
    {
        sgt[k].val = z;
        return;
    }
    int m = (l+r)>>1;
    if(x<=m) modify(x,z,ls(k));
    else modify(x,z,rs(k));
    pushup(k);
}
int query(int x,int y,int k=1)
{
    int l=sgt[k].l, r=sgt[k].r;
    if(x<=l&&y>=r) return sgt[k].val;
    int m = (l+r)>>1;
    int res = 0;
    if(x<=m) res = query(x,y,ls(k));
    if(y>m)  res = max(res, query(x,y,rs(k)));
    return res;
}
int query_p(int x,int y)
{
    int res = 0;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        res = max(res, query(dfn[top[x]], dfn[x]));
        x = fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    res = max(res, query(dfn[x], dfn[y]));
    return res;
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
    memset(Head, -1, sizeof(Head));
    int n,m;
    cin>>n>>m;
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
    modify(1,1);
    while(m--)
    {
        char opt;
        int x;
        cin>>opt>>x;
        if(opt=='Q') cout<<nfd[query_p(1,x)]<<'\n';
        else modify(dfn[x], dfn[x]);
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
