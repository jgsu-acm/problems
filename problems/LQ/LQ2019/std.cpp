#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <bitset>
const int maxn = 10;
const int maxm = 20;
struct E { int to,next; } Edge[maxm];
int tot, Head[maxn];
inline void AddEdge(int u,int v)
{
    Edge[tot]={v,Head[u]};
    Head[u]=tot++;
    Edge[tot]={u,Head[v]};
    Head[v]=tot++;
}
bool vis[maxn];
bitset<7> exists;
int dfs(int u)
{
    int sum = 1;
    vis[u] = true;
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(vis[v]||!exists[v-1]) continue;
        sum += dfs(v);
    }
    return sum;
}
#include <cstring> 
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    clock_t c1 = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    memset(Head,-1,sizeof(Head));
    AddEdge(1,2); AddEdge(1,6);
    AddEdge(2,3); AddEdge(2,7);
    AddEdge(3,4); AddEdge(3,7);
    AddEdge(4,5);
    AddEdge(5,6); AddEdge(5,7);
    AddEdge(6,7);
    int cnt = 0;
    for(int i=1;i<(1<<7);i++)
    {
        memset(vis, false, sizeof(vis));
        exists = bitset<7>(i);
        for(int j=0;;j++)
        {
            if(exists[j])
            {
                if(dfs(j+1)==__builtin_popcount(i)) cnt++;
                break;
            }
        }
    }
    cout<<cnt<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
