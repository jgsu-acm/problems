#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <cmath>
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
    int cnt=100, mink=100;
    for(int k=1;k<=100;k++)
    {
        int t = ceil(100.0/k) + k;
        if(t<cnt)
        {
            cnt = t;
            mink = k;
        }
    }
    cout<<mink<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
