#include <iostream>
#include <tuple>
#include <algorithm>
#include <climits>
using namespace std;
const int maxn = 1e4+5;
const int maxm = 5e5+5;
typedef tuple<int,int,int> tp3;
tp3 Edge[maxm];
long long dis[maxn];
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int n,m,s;
    cin>>n>>m>>s;
    fill(dis+1, dis+1+n, INT_MAX);
    dis[s]=0;
    int u,v,w;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        Edge[i]={u,v,w};
    }
    for(int i=1;i<n;i++)
    {
        bool flag=true;
        for(int j=0;j<m;j++)
        {
            tie(u,v,w) = Edge[j];
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                flag=false;
            }
        }
        if(flag) break;
    }
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<' ';
    return 0;
}