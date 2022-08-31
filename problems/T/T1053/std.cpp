#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
const int maxn = 1e5+5;
typedef long long ll;
vector<int> G[maxn];
int d[maxn], siz[maxn], ss[maxn], dp[maxn];
void dfs1(int u,int f)
{
    siz[u] = 1;
    for(auto v : G[u])
    {
        if(v==f) continue;
        dfs1(v,u);
        siz[u] += siz[v];
        ss[u] += 2*siz[v]-1;
    }
}
void dfs2(int u,int f)
{
    if(u!=1) dp[u] = dp[f]+d[f]+ss[f]-(2*siz[u]-1);
    for(auto v : G[u])
    {
        if(v==f) continue;
        dfs2(v,u);
    }
}
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
        d[u]++, d[v]++;
    }
    dfs1(1,0);
    dfs2(1,0);
    int q;
    cin>>q;
    while(q--)
    {
        int opt, u;
        cin>>opt>>u;
        if(opt==1) cout<<siz[u]*2-1<<'\n';
        else cout<<dp[u]<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
