#include <iostream>
#include <chrono>
using namespace std;
//==========================================
int a[15];
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    for(int i=0;i<10;i++) a[i]=2021;
    for(int i=1;;i++)
    {
        int x = i;
        while(x)
        {
            if(a[x%10]--==0)
            {
                cout<<i-1<<endl;
                goto end;
            }
            x /= 10;
        }
    }
end:
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
