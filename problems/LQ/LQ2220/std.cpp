#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <cmath>
typedef long long ll;
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
    int n;
    cin>>n;
    ll ans = 0;
    vector<ll> pre, cur;
    for(int i=0;i<n;i++)
    {
        cur.clear();
        ll h;
        cin>>h;
        while(h>1)
        {
            cur.push_back(h);
            h = sqrt(h/2+1);
        }
        int cnt = 0;
        for(auto it1=pre.rbegin(),it2=cur.rbegin();it1!=pre.rend()&&it2!=cur.rend();++it1,++it2)
            if(*it1==*it2) cnt++;
        ans += cur.size()-cnt;
        pre = cur;
    }
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
