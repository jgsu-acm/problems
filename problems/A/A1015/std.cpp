#include <iostream>
using namespace std;
const int maxn = 1e4+5;
struct E { int to,next; } Edge[maxn<<1];    // 链式前向星，因为是树所以开2倍maxn大小即可
int tot,Head[maxn];
inline void AddEdge(int u,int v) { Edge[tot]={v,Head[u]}; Head[u]=tot++; }
int siz[maxn];
void dfs(int u,int f)
{
    siz[u]=1;   // 每个结点的大小等于自己的所有子树的大小之和加1（因为还包括结点自己）
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f) continue;  // 防止走回父亲
        dfs(v,u);   // 计算v子树大小
        siz[u]+=siz[v];     // 在u子树大小中加上v子树大小
    }
}
#include <cstring>
int main()
{
    memset(Head,-1,sizeof(Head));   // 链式前向星-1写法，将Head数组初始化为-1
    int n; cin>>n;
    for(int i=1,u,v;i<n;i++)        // 读入数据，注意正反加两条边
        cin>>u>>v, AddEdge(u,v), AddEdge(v,u);
    for(int rt=1;rt<=n;rt++)
    {
        dfs(rt, 0);
        for(int i=1;i<=n;i++)
            cout<<siz[i]<<' ';
        cout<<endl;
    }
    return 0;
}