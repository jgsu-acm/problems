#include <iostream>
using namespace std;
const int maxn = 2e5+5;
int fa[maxn];
int find(int x) { return x==fa[x]?x:fa[x]=find(fa[x]); }
inline void merge(int x,int y) { fa[find(x)]=find(y); }
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    while(m--)
    {
        int opt,x,y;
        cin>>opt>>x>>y;
        if(opt==1) merge(x,y);
        else cout<<(find(x)==find(y)?'Y':'N')<<endl;
    }
    return 0;
}