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
int ans, dp[maxn];
void dfs(int u,int f)
{
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f) continue;
        dfs(v,u);
        ans = max(ans, dp[u]+dp[v]+1);
        dp[u] = max(dp[u], dp[v]+1);
    }
}
#include <cstring>
int main()
{
    memset(Head,-1,sizeof(Head));
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        AddEdge(u,v);
        AddEdge(v,u);
    }
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}