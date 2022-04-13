#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
const int maxn = 2025;
const int maxm = maxn*maxn/2;
typedef pair<int,int> pii;
struct E { int to,w,next; } Edge[maxm<<1];
int tot,Head[maxn];
inline void AddEdge(int u,int v,int w)
{
    Edge[tot]={v,w,Head[u]};
    Head[u]=tot++;
}
int dis[maxn];
bool vis[maxn];
priority_queue<pii, vector<pii>, greater<pii>> pq;
void dijkstra(int s)
{
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    pq.emplace(0,s);
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
                pq.emplace(dis[v],v);
            }
        }
    }
}
inline int lcm(int a,int b) { return a*b/__gcd(a,b); }
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
    int n = 2021;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(abs(i-j)<=21)
            {
                int w = lcm(i,j);
                AddEdge(i,j,w);
                AddEdge(j,i,w);
            }
        }
    }
    dijkstra(1);
    cout<<dis[n]<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
