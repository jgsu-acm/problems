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
#include <cstring>
#include <queue>
#include <algorithm>
#include <climits>
const int maxn = 1e5+5;
const int maxm = 2e5+5;
struct E
{
    int to,w,next;
}Edge[maxm];
int tot,Head[maxn];
inline void AddEdge(int u,int v,int w)
{
    Edge[tot]={v,w,Head[u]};
    Head[u]=tot++;
}
long long dis[maxn];
bool vis[maxn];
typedef pair<long long,int> pii;
priority_queue<pii, vector<pii>, greater<pii>> pq;  //! 小根堆
void dijkstra(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    dis[s]=0;
    pq.push({0, s});
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=Head[u];~i;i=Edge[i].next)
        {
            int v = Edge[i].to;
            if(dis[u]+Edge[i].w<dis[v])
            {
                dis[v]=dis[u]+Edge[i].w;
                pq.push({dis[v], v});
            }
        }
    }
}
void spfa(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    dis[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u]=false;
        for(int i=Head[u];~i;i=Edge[i].next)
        {
            int v = Edge[i].to;
            if(dis[u]+Edge[i].w<dis[v])
            {
                dis[v] = dis[u]+Edge[i].w;
                if(!vis[v])
                {
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
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
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    memset(Head,-1,sizeof(Head));
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        AddEdge(u,v,w);
    }
    dijkstra(1);
    // spfa(1);
    for(int i=1;i<=n;i++) cout<<dis[i]<<' ';
    //======================================
    exit();
}