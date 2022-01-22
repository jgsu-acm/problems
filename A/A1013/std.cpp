#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
//==========================================
const int MAXN = 5e5 + 5;
const int MOD = 1e9+7;
typedef long long ll;
ll a[MAXN],b[MAXN];
ll prea[MAXN],preb[MAXN],preapreb[MAXN];
ll preprea[MAXN],prepreb[MAXN],prepreapreb[MAXN];
int n;
inline void input(ll a[])
{
    for(int i=1;i<=n;i++)
        cin>>a[i];
}
void calcPre(ll a[], ll pre[])
{
    for(int i=1;i<=n;i++)
        pre[i]=(a[i]+pre[i-1]) % MOD;
}
void getMul(ll a[], ll b[], ll c[])
{
    for(int i=1;i<=n;i++)
        c[i]=a[i]*b[i]%MOD;
}
ll solve()
{
    ll sum = 0;
    for(int l=1;l<=n;l++)
    {
        sum += prepreapreb[n]-prepreapreb[l-1]+MOD;
        sum %= MOD;
        sum += ((n-l+1)*prea[l-1]%MOD)*(preb[l-1]%MOD);
        sum %= MOD;
        sum -= (preprea[n]-preprea[l-1])*preb[l-1]%MOD;
        sum += MOD;
        sum %= MOD;
        sum-= (prepreb[n]-prepreb[l-1])*prea[l-1]%MOD;
        sum += MOD;
        sum %= MOD;
    }
    return sum;
}
signed main(signed argc, char const *argv[])
{
    clock_t c1 = clock();
#ifdef LOCAL
    system("cls");
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    //======================================
    cin>>n;
    input(a);
    input(b);
    calcPre(a, prea);
    calcPre(b, preb);
    getMul(prea, preb, preapreb);
    calcPre(prea, preprea);
    calcPre(preb, prepreb);
    calcPre(preapreb, prepreapreb);
    cout<<solve()<<endl;
    //======================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}