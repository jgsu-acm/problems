#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1005;
int fa[2][maxn*maxn];       // 两个并查集，一维下标为0时是白子的并查集，1时是黑子的并查集。
int find(int k, int x) { return x==fa[k][x]?x:x=find(k, fa[k][x]); }
inline void merge(int k,int x,int y) { fa[k][find(k,x)]=find(k,y); }
int n,m,zhan[2], kuai[2], board[maxn][maxn];
inline int hs(int x,int y) { return (x-1)*n+y; }
int main()
{
    memset(board, -1, sizeof(board));
    cin>>n>>m;
    for(int i=1;i<=n*n;i++) fa[0][i]=fa[1][i]=i;    // 初始化并查集
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        int k = i%2;
        board[x][y]=k;  // 存下当前位置棋子黑白
        ++kuai[k];      // 如果是孤立棋子的话块数就会+1
        int cnt = 0;    // 每与周围同色棋子合并一下cnt就+1，当cnt为2时代表这一着棋是粘
        if(board[x-1][y]==board[x][y]&&find(k, hs(x,y))!=find(k, hs(x-1,y)))    // 上
        {
            merge(k, hs(x,y), hs(x-1,y));
            --kuai[k];  // 每合并一次，块数就会减一
            ++cnt;
        }
        if(board[x+1][y]==board[x][y]&&find(k, hs(x,y))!=find(k, hs(x+1,y)))    // 下
        {
            merge(k, hs(x,y), hs(x+1,y));
            --kuai[k];
            if(++cnt==2) ++zhan[k];
        }
        if(board[x][y-1]==board[x][y]&&find(k, hs(x,y))!=find(k, hs(x,y-1)))    // 左
        {
            merge(k, hs(x,y), hs(x,y-1));
            --kuai[k];
            if(++cnt==2) ++zhan[k];
        }
        if(board[x][y+1]==board[x][y]&&find(k, hs(x,y))!=find(k, hs(x,y+1)))    // 右
        {
            merge(k, hs(x,y), hs(x,y+1));
            --kuai[k];
            if(++cnt==2) ++zhan[k];
        }
    }
    cout<<zhan[1]<<' '<<zhan[0]<<endl<<kuai[1]<<' '<<kuai[0]<<endl;
    return 0;
}