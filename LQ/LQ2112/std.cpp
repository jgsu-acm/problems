#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
//==========================================
const int MAXN = 1e5+5;
struct E
{
    int to,next;
}Edge[MAXN];
int tot,Head[MAXN];
inline void AddEdge(int u,int v)
{
    Edge[tot]=(E){v,Head[u]};
    Head[u]=tot++;
}
int dp[MAXN];
void dfs(int u)
{
    int sum = 0, mx = 0;
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        sum++;
        dfs(v);
        mx = max(mx, dp[v]);
    }
    dp[u] = mx + sum;
}
#include <cstring>
signed main(signed argc, char const *argv[])
{
    clock_t c1 = clock();
#ifdef LOCAL
    system("cls");
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    //======================================
    memset(Head,-1,sizeof(Head));
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int fa;
        cin>>fa;
        AddEdge(fa,i);
    }
    dfs(1);
    cout<<dp[1]<<endl;
    //======================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}