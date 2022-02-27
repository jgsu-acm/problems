#include <iostream>
using namespace std;
const int maxn = 1e5+5;
int pre[maxn];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)       // O(n)处理出pre (pre[i]=pre[i-1]+a[i])
    {
        int x;
        cin>>x;
        pre[i]=pre[i-1]+x;
    }
    while(m--)                  // O(m)处理所有询问
    {
        int l,r;
        cin>>l>>r;
        cout<<pre[r]-pre[l-1]<<endl;
    }
}