#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <numeric>
#include <tuple>
#include <algorithm>
#include <string>
#include <vector>
const int maxn = 2025;
int fa[maxn];
int find(int x) { return x==fa[x]?x:fa[x]=find(fa[x]); }
inline void merge(int x,int y) { fa[find(x)]=find(y); }
vector<tuple<int,int,int>> edge;
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
    int n = 2021;
    iota(fa+1, fa+1+n, 1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            string s1=to_string(i), s2=to_string(j);
            if(s1.length()<s2.length())
                s1 = string(s2.length()-s1.length(), '0') + s1;
            else if(s2.length()<s1.length())
                s2 = string(s1.length()-s2.length(), '0') + s2;
            int sum = 0;
            for(int i=0;i<s1.length();i++)
                if(s1[i]!=s2[i])
                    sum += s1[i]-'0'+s2[i]-'0';
            edge.emplace_back(sum,i,j);
        }
    }
    sort(edge.begin(), edge.end());
    int ans=0, cnt=0;
    for(auto [w,u,v] : edge)
    {
        if(find(u)!=find(v))
        {
            ans += w;
            merge(u,v);
            if(++cnt==n-1) break;
        }
    }
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
