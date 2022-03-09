#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <queue>
#include <tuple>
const int maxn = 2e5+5;
typedef tuple<int,int,int> tp3;
int v[maxn];
priority_queue<tp3, vector<tp3>, greater<tp3>> pq;
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
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    while(m--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        while(!pq.empty()&&get<0>(pq.top())<=a)
        {
            auto [_,j,k] = pq.top();
            pq.pop();
            v[j]+=k;
        }
        if(v[b]>=d)
        {
            v[b]-=d;
            cout<<v[b]<<'\n';
            pq.emplace(a+c, b, d);
        }
        else cout<<-1<<'\n';
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
