#include <iostream>
#include <ctime>
using namespace std;
clock_t c1;
inline void exit()
{
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    exit(0);
}
//==========================================
int red=15, nxt=1;
int shot(int x)
{
    if(nxt==1)
    {
        if(x==nxt)
        {
            nxt=8;
            red--;
            return 1;
        }
        else return -max(4,x);
    }
    else if(2<=nxt&&nxt<=7)
    {
        if(x==nxt)
        {
            nxt++;
            return x;
        }
        else return -max(4, x);
    }
    else
    {
        if(2<=x&&x<=7)
        {
            if(!red) nxt=2;
            else nxt=1;
            return x;
        }
        else
        {
            nxt=1;
            return -4;
        }
    }
}
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    c1 = clock();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n,m;
    cin>>n>>m;
    int sum1=0, sum2=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        int tmp = shot(x);
        if(i==n&&tmp<0) sum2-=tmp;
        else sum1+=tmp;
    }
    if(nxt==8) nxt=1;
    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        int tmp = shot(x);
        if(i==m&&tmp<0) sum1-=tmp;
        else sum2+=tmp;
    }
    cout<<sum1<<' '<<sum2<<endl;
    //======================================
    exit();
}