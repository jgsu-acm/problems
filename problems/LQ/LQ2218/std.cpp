#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <unordered_map>
typedef long long ll;
typedef pair<int,int> pii;
template<> struct std::hash<pii> { ll operator()(const pii& p) const { return (ll(p.first)>>32)+p.second; } };
unordered_map<pii, pii> mp;
int ans;
void dfs(int x,int y,int r)
{
    for(int i=x-r;i<=x+r;i++)
    {
        ll t = (ll)(i-x)*(i-x);
        for(int j=y;t+(ll)(j-y)*(j-y)<=r*r;j++)
        {
            auto it = mp.find({i,j});
            if(it==mp.end()) continue;
            ans += it->second.second;
            int t = it->second.first;
            mp.erase(it);
            dfs(i,j,t);
        }
        for(int j=y;t+(ll)(j-y)*(j-y)<=r*r;j--)
        {
            auto it = mp.find({i,j});
            if(it==mp.end()) continue;
            ans += it->second.second;
            int t = it->second.first;
            mp.erase(it);
            dfs(i,j,t);
        }
    }
}
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
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int x,y,r;
        cin>>x>>y>>r;
        auto p = pii(x,y);
        mp[p].second++;
        mp[p].first = max(mp[p].first, r);
    }
    for(int i=0;i<m;i++)
    {
        if(ans==n) break;
        int x,y,r;
        cin>>x>>y>>r;
        dfs(x,y,r);
    }
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
