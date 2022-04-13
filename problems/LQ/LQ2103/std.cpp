#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <set>
#include <tuple>
typedef tuple<int,int,int> tp3;
set<tp3> s;
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
    int n=20, m=21;
    for(int x=0;x<n;x++)
    {
        for(int y=0;y<m;y++)
        {
            for(int p=0;p<n;p++)
            {
                for(int q=0;q<m;q++)
                {
                    if(p==x&&q==y) continue;
                    int a = q-y;
                    int b = x-p;
                    int g = __gcd(a,b);
                    a/=g, b/=g;
                    int c = -(a*x+b*y);
                    s.emplace(a,b,c);
                }
            }
        }
    }
    cout<<s.size()<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
