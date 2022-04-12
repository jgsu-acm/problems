#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
//==========================================
const int MAXN = 25;
int amount[MAXN];
#include <cstring>
signed main(signed argc, char const *argv[])
{
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        memset(amount, 0, sizeof(amount));
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            for(int j=0;x;j++)
            {
                if(x % 2) amount[j]++;
                x /= 2;
            }
        }
        int ans = 0;
        for(int i=20;i>=0;i--)
        {
            int a=amount[i], b=n-a;
            if(a)
            {
                if(b%2)
                {
                    if(a%2)
                    {
                        if(a==1) ans=1;
                        else ans=-1;
                        break;
                    }
                }
                else if(a%2)
                {
                    ans = 1;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    //======================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
