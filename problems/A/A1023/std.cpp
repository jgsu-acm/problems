#include <iostream>
using namespace std;
const int maxn = 2e5+5;
int mp[maxn<<1];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        mp[x]=i;
    }
    int ans = 0;
    for(int k=3;k<=2*n-1;k++)
    {
        for(int i=1;i*i<k;i++)
        {
            if(k%i) continue;
            int j = k/i;
            if(mp[i]&&mp[j]&&mp[i]+mp[j]==k)
                ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}