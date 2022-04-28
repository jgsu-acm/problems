#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 5e5+5;
typedef long long ll;
int n;
ll c[maxn];
int lowbit(int x) { return x&-x; }
void modify(int x,int z)
{
    for(int i=x;i<=n;i+=lowbit(i)) c[i] += z;
}
ll query(int x)
{
    ll sum = 0;
    for(int i=x;i;i-=lowbit(i)) sum += c[i];
    return sum;
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
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        modify(i,x);
    }
    while(m--)
    {
        int opt,x,y;
        cin>>opt>>x>>y;
        if(opt==1) modify(x,y);
        else cout<<query(y)-query(x-1)<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
