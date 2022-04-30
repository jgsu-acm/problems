#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxk = 10;
const int maxn = 1e4*(maxk+1)+5;
const int maxm = (5e4*(maxk*2+1))*2+maxk+5;
typedef pair<int,int> pii;
struct E { int to,w,next; } Edge[maxm];
int tot,Head[maxn];
inline void AddEdge(int u,int v,int w)
{
    Edge[tot] = {v,w,Head[u]};
    Head[u] = tot++;
}
int dis[maxn];
bool vis[maxn];
priority_queue<pii, vector<pii>, greater<pii>> pq;
void dijkstra(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    pq.emplace(0, s);
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(int i=Head[u];~i;i=Edge[i].next)
        {
            int v = Edge[i].to;
            if(dis[u]+Edge[i].w<dis[v])
            {
                dis[v] = dis[u]+Edge[i].w;
                pq.emplace(dis[v], v);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(Head, -1, sizeof(Head));
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        for(int j=0;j<=k;j++)
        {
            AddEdge(u+j*n, v+j*n, w);
            AddEdge(v+j*n, u+j*n, w);
            if(j==k) continue;
            AddEdge(u+j*n, v+(j+1)*n, 0);
            AddEdge(v+j*n, u+(j+1)*n, 0);
        }
    }
    for(int i=1;i<=k;i++) AddEdge(n+(i-1)*n, n+i*n, 0);
    dijkstra(1);
    int ans = dis[n+k*n]*4;
    cout<<ans<<endl;
    if(!ans) cout<<"Identified as: Purely Network Connection."<<endl;
    return 0;
}
