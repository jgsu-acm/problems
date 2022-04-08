#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
const int maxn = 1e7+5;
int phi[maxn];
bool vis[maxn];
vector<int> pri;
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
    phi[1] = 1;
    int n = 1e7;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])
        {
            pri.push_back(i);
            phi[i] = i-1;
        }
        for(int j : pri)
        {
            if((long long)i*j>n) break;
            vis[i*j] = true;
            if(i%j==0)
            {
                phi[i*j] = phi[i]*j;
                break;
            }
            else phi[i*j] = phi[i]*(j-1);
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        cout<<phi[x]<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
