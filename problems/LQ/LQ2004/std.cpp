#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <cmath>
int a[] = {
    9090400,
    8499400,
    5926800,
    8547000,
    4958200,
    4422600,
    5751200,
    4175600,
    6309600,
    5865200,
    6604400,
    4635000,
    10663400,
    8087200,
    4554000,
};
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    clock_t c1 = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n = sizeof(a)/sizeof(int);
    int ans = 0x3f3f3f3f;
    for(int i=1;i<(1<<n)-1;i++)
    {
        int sum1=0, sum2=0;
        int tmp = i;
        for(int j=0;tmp;j++)
        {
            if(tmp%2) sum1+=a[j];
            else sum2+=a[j];
            tmp/=2;
        }
        ans = min(ans, abs(sum1-sum2));
    }
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
