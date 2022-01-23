#include <iostream>
#include <ctime>
#include <cstdio>
#include <cctype>
namespace FastIO
{
char buf[1 << 21], buf2[1 << 21], a[20], *p1 = buf, *p2 = buf, hh = '\n';
int p, p3 = -1;
void read() {}
void print() {}
inline int getc()
{
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;
}
inline void flush()
{
    fwrite(buf2, 1, p3 + 1, stdout), p3 = -1;
}
template <typename T, typename... T2>
inline void read(T &x, T2 &... oth)
{
    int f = 0;
    x = 0;
    char ch = getc();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = 1;
        ch = getc();
    }
    while (isdigit(ch))
    {
        x = x * 10 + ch - 48;
        ch = getc();
    }
    x = f ? -x : x;
    read(oth...);
}
template <typename T, typename... T2>
inline void print(T x, T2... oth)
{
    if (p3 > 1 << 20)
        flush();
    if (x < 0)
        buf2[++p3] = 45, x = -x;
    do
    {
        a[++p] = x % 10 + 48;
    } while (x /= 10);
    do
    {
        buf2[++p3] = a[p];
    } while (--p);
    buf2[++p3] = hh;
    print(oth...);
}
} // namespace FastIO
#define read FastIO::read
#define print FastIO::print
//======================================
#include <queue>
#include <cstring>
using std::queue;
using std::min;
const int maxn = 1e6+5;
struct E
{
    int to,next,w;
}Edge[maxn*2];
int tot,Head[maxn];
int cur[maxn];
inline void AddEdge(int u,int v,int w)
{
    Edge[tot].to=v,Edge[tot].w=w,Edge[tot].next=Head[u],Head[u]=tot++;
    Edge[tot].to=u,Edge[tot].w=0,Edge[tot].next=Head[v],Head[v]=tot++;
}
int s,l;
int dep[maxn];
bool bfs()
{
    queue<int> q;
    memset(dep,0,sizeof(dep));
    q.push(s);
    dep[s]=1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=Head[u];~i;i=Edge[i].next)
        {
            int &v=Edge[i].to,&w=Edge[i].w;
            if(!dep[v]&&w>0)
                dep[v]=dep[u]+1,q.push(v);
        }
    }
    if(dep[l]) return true;
    else return false;
}
int dfs(int u,int f)
{
    if(u==l) return f;
    for(int i=cur[u];~i;i=Edge[i].next)
    {
        cur[u]=i;
        int &v=Edge[i].to,&w=Edge[i].w;
        if(dep[v]==dep[u]+1&&w)
        {
            int tmp = dfs(v,min(w,f));
            if(tmp>0)
            {
                w-=tmp;
                Edge[i^1].w+=tmp;
                return tmp;
            }
        }
    }
    return 0;
}
int Dinic()
{
    int ret=0;
    while(bfs())
    {
        memcpy(cur,Head,sizeof(Head));
        while(int tmp=dfs(s,1<<30))
            ret+=tmp;
    }
    return ret;
}
int main(int argc, char const *argv[])
{
    clock_t c1 = clock();
    //======================================
    memset(Head,-1,sizeof(Head));
    int n,m,e;
    read(n,m,e);
    s=1,l=2+n+m;
    for(int i=1;i<=e;i++)
    {
        int u,v;
        read(u,v);
        if(u>n||v>m) continue;
        AddEdge(u+1,v+n+1,1);
    }
    for(int i=1;i<=n;i++)
        AddEdge(s,i+1,1);
    for(int i=1;i<=m;i++)
        AddEdge(i+1+n,l,1);
    print(Dinic());
    //======================================
    FastIO::flush();
    std::cerr << "Time:" << clock() - c1 << "ms" << std::endl;
    return 0;
}