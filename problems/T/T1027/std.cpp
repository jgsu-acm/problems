#include <iostream>
using namespace std;
const int maxn = 1e5+5;
struct E
{
    int to,next;
}Edge[maxn<<1];
int tot,Head[maxn];
inline void AddEdge(int u,int v)
{
    Edge[tot]={v,Head[u]};
    Head[u]=tot++;
}
int n,rt,siz[maxn],maxp[maxn];
void dfs1(int u,int f)
{
    siz[u]=1;
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f) continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        maxp[u]=max(maxp[u], siz[v]);
    }
    maxp[u]=max(maxp[u],n-siz[u]);
    if(maxp[u]<maxp[rt]) rt=u;
}
long long ans;
void dfs2(int u,int f,int dep)
{
    ans += dep;
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f) continue;
        dfs2(v,u,dep+1);
    }
}
#include <cstring>
int main()
{
    memset(Head,-1,sizeof(Head));
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        AddEdge(u,v);
        AddEdge(v,u);
    }
    maxp[rt]=n;
    dfs1(1,0);
    dfs2(rt,0,0);
    cout<<ans<<endl;
    return 0;
}