#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <string>
#include <cctype>
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
    string s;
    cin>>s;
    for(auto it=s.begin(); it!=s.end(); ++it)
    {
        if(isdigit(*it)) cout<<string(*it-'1', *(it-1));
        else cout<<*it;
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
