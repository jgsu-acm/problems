#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <string>
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
    int cnt = 0;
    for(int i=1;i<=2020;i++)
    {
        string s = to_string(i);
        cnt += count(s.begin(), s.end(), '2');
    }
    cout<<cnt<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
