#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e4+5;
const int maxw = 1e7+5;
typedef long long ll;
ll w[maxn], v[maxn];
ll dp[maxw];
int main()
{
    int n, W;
    cin>>n>>W;
    for(int i=1;i<=n;i++)
        cin>>w[i]>>v[i];
    for(int i=1;i<=n;i++)
        for(int j=W;j>=w[i];j--)
            dp[j]=max(dp[j-w[i]]+v[i], dp[j]);
    cout<<dp[W]<<endl;
    return 0;
}