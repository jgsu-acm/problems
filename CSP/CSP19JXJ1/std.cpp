#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
//==========================================
const int MAXN = 1e5 + 5;
signed main(signed argc, char const *argv[])
{
    clock_t c1 = clock();
#ifdef LOCAL
    system("cls");
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    //======================================
    int a,b,c;
    cin>>a>>b>>c;
    cout<<((long long)a*a>(long long)b*c?"Alice":"Bob")<<endl;
    //======================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}