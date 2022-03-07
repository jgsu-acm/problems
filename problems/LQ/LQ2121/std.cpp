#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <string>
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
    for(int i=0;i<5;i++)
    {
        string s;
        cin>>s;
        if(s[0]==s[2]&&s[1]+1==s[3])
            ++cnt;
    }
    cout<<cnt<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
