#include <iostream>
#include <ctime>
using namespace std;
//==========================================
const int maxn = 1e5+5;
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
    int mul = 1;
    for(int i=3;i<=2021;i+=2)
        mul = mul * i % 100000;
    cout<<mul<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
