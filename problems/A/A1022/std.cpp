#include <iostream>
using namespace std;
const int maxn = 1e7+5;
int v[maxn], dp[maxn];
int main()
{
    int W, n;
    cin>>W>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
        for(int j=v[i];j<=W;j++)
            dp[j]=max(dp[j-v[i]]+v[i],dp[j]);
    cout<<W-dp[W]<<endl;
    return 0;
}