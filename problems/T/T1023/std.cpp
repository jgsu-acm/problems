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
const int maxn = 5e5+5;
struct E
{
    int to,next;
} Edge[maxn<<1];
int tot, Head[maxn];
inline void AddEdge(int u,int v)
{
    Edge[tot] = {v,Head[u]};
    Head[u] = tot++;
}
int dp[20][maxn], dep[maxn];
void dfs(int u,int f)
{
    dep[u] = dep[f]+1;
    dp[0][u] = f;
    for(int i=1; (1<<i)<dep[u]; i++)
        dp[i][u] = dp[i-1][dp[i-1][u]];
    for(int i=Head[u]; ~i; i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f) continue;
        dfs(v, u);
    }
}
#include <cmath>
int lca(int u,int v)
{
    // 1. 先把 u,v 调到同一个深度
    if(dep[u]<dep[v]) swap(u,v);
    while(dep[u]!=dep[v])
        u = dp[(int)log2(dep[u]-dep[v])][u];
    // 2. 再令 u,v 同时向上跳，直到相遇，即为 lca(u,v)
    for(int i=19;i>=0;i--)
    {
        if(dp[i][u]!=dp[i][v])
            u=dp[i][u], v=dp[i][v];
    }
    if(u==v) return u;
    else return dp[0][u];
}
#include <cstring>
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
    memset(Head, -1, sizeof(Head));
    int n,m,s;
    cin>>n>>m>>s;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        AddEdge(u,v);
        AddEdge(v,u);
    }
    dfs(s,0);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        cout<<lca(u,v)<<'\n';
    }
    //======================================
    exit();
}