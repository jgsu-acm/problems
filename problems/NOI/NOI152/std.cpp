#include <cstdio>
#include <cstring>
const int maxn = 1e5+5;
struct E
{
    int to,next;
}Edge[maxn<<1];
int tot,Head[maxn];
inline void AddEdge(int u,int v)
{
    Edge[tot]=(E){v,Head[u]};
    Head[u]=tot++;
}
int siz[maxn],son[maxn],dep[maxn],fa[maxn];
void dfs1(int u,int f)
{
    fa[u]=f,dep[u]=dep[f]+1,siz[u]=1;
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f) continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]])
            son[u]=v;
    }
}
int tim,top[maxn],dfn[maxn];
void dfs2(int u,int t)
{
    top[u]=t;
    dfn[u]=++tim;
    if(!son[u]) return;
    dfs2(son[u],t);
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}
struct Node
{
    int l,r,f,val;
}sgt[maxn<<2];
#define ls(k) (k<<1)
#define rs(k) (k<<1|1)
#define pushup(k) sgt[k].val=sgt[ls(k)].val+sgt[rs(k)].val
void pushdw(int k)
{
    sgt[ls(k)].f=sgt[rs(k)].f=sgt[k].f;
    sgt[ls(k)].val=(sgt[ls(k)].r-sgt[ls(k)].l+1)*sgt[k].f;
    sgt[rs(k)].val=(sgt[rs(k)].r-sgt[rs(k)].l+1)*sgt[k].f;
    sgt[k].f=-1;
}
void build(int l,int r,int k=1)
{
    sgt[k].l=l,sgt[k].r=r,sgt[k].f=-1;
    if(l==r) return;
    int m = (l+r)>>1;
    build(l,m,ls(k));
    build(m+1,r,rs(k));
}
void modify(int x,int y,int z,int k=1)
{
    int l=sgt[k].l,r=sgt[k].r;
    if(x<=l&&y>=r)
    {
        sgt[k].f=z;
        sgt[k].val=(r-l+1)*z;
        return;
    }
    if(~sgt[k].f) pushdw(k);
    int m = (l+r)>>1;
    if(x<=m) modify(x,y,z,ls(k));
    if(y>m) modify(x,y,z,rs(k));
    pushup(k);
}
int query(int x,int y,int k=1)
{
    int l=sgt[k].l,r=sgt[k].r;
    if(x<=l&&y>=r) return sgt[k].val;
    if(~sgt[k].f) pushdw(k);
    int sum=0,m=(l+r)>>1;
    if(x<=m) sum+=query(x,y,ls(k));
    if(y>m) sum+=query(x,y,rs(k));
    return sum;
}
inline void modifyc(int x,int y)
{
    while(top[y]!=1)
    {
        modify(dfn[top[y]],dfn[y],1);
        y = fa[top[y]];
    }
    modify(dfn[x],dfn[y],1);
}
inline int abs(int x) { return x>0?x:-x; }
int main()
{
    memset(Head,-1,sizeof(Head));
    int n,m,x;
    char ch[15];
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&x);
        x++;
        AddEdge(i,x);
        AddEdge(x,i);
    }
    dfs1(1,0);
    dfs2(1,1);
    build(1,n);
    scanf("%d",&m);
    while(m--)
    {
        scanf("%s%d",ch,&x);
        x++;
        int t = sgt[1].val;
        if(ch[0]=='i') modifyc(1,x);
        else modify(dfn[x],dfn[x]+siz[x]-1,0);
        printf("%d\n",abs(sgt[1].val-t));
    }
    return 0;
}