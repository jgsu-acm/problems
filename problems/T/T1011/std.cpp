#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e4+5;
const int maxw = 1e7+5;
typedef long long ll;
ll m[maxn], w[maxn], v[maxn];
ll dp[maxw];
int main()
{
    int n, W;
    cin>>n>>W;
    for(int i=1;i<=n;i++)
        cin>>m[i]>>w[i]>>v[i];
    for(int i=1;i<=n;i++)
        for(int j=W;j>=0;j--)
            for(int k=0;k*w[i]<=j&&k<=m[i];k++)
                dp[j]=max(dp[j-k*w[i]]+k*v[i], dp[j]);
    cout<<dp[W]<<endl;
    return 0;
}