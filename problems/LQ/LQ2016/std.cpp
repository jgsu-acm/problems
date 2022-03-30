#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <algorithm>
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
    int n = 2020;
    int cnt = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(__gcd(i,j)==1)
                cnt++;
    cout<<cnt<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
