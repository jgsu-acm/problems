#include <iostream>
#include <queue>
using namespace std;
const int maxn = 5005;
const int maxm = 2e5+5;
struct E
{
    int u,v,w;      //一条连接uv的边，权为w
    //! 不需要储存从哪到哪
    //? 连的是哪两个
    bool operator<(const E oth) const {
        return w>oth.w;
    }
}Edge[maxm];
priority_queue<E> pq;
int fa[maxn];
int find(int x) { return x==fa[x]?x:fa[x]=find(fa[x]); }
inline void merge(int x,int y) { fa[find(x)]=find(y); }
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i;
    while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        pq.push({u,v,w});
    }
    int ans = 0;
    while(!pq.empty())
    {
        E tmp = pq.top();
        pq.pop();
        if(find(tmp.u)==find(tmp.v)) continue;
        merge(tmp.u,tmp.v);
        ans += tmp.w;
        n--;
        if(n==1) break;
    }
    if(n==1) cout<<ans<<endl;
    else cout<<"Disconnected"<<endl;
    return 0;
}