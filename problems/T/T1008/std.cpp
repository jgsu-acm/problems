#include <iostream>
using namespace std;
const int maxn = 2005;
int a[maxn][maxn], pre[maxn][maxn];
int main()
{
    int n,m,p,q;
    cin>>n>>m>>p>>q;
    int mx = 0xcfcfcfcf;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x;
            cin>>x;
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+x;
            if(i>=p&&j>=q)
                mx=max(mx, pre[i][j]-pre[i-p][j]-pre[i][j-q]+pre[i-p][j-q]);
        }
    }
    cout<<mx<<endl;
    return 0;
}