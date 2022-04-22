#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cstring>
const int maxn = 1e7+5;
const int mod = 1e9+7;
typedef long long ll;
class calculator { public: virtual int calc(int n) = 0; };
class calculator1 : public calculator
{
private:
    ll dp[3];
public:
    int calc(int n)
    {
        dp[0]=1, dp[1]=2, dp[2]=5;
        for(int i=0;i<n-3;i++)
        {
            ll t = (dp[2]*2+dp[0])%mod;
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = t;
        }
        return n<4?dp[n-1]:dp[2];
    }
};
class calculator2 : public calculator
{
private:
    struct Matrix
    {
        ll ele[3][3];
        void init() { memset(ele, 0, sizeof(ele)); }
        Matrix operator*(Matrix& b)
        {
            Matrix res;
            res.init();
            for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                    for(int k=0;k<3;k++)
                        res.ele[i][j] = (res.ele[i][j] + ele[i][k]*b.ele[k][j])%mod;
            return res;
        }
    };
public:
    int calc(int n)
    {
        switch(n)
        {
        case 1: return 1;
        case 2: return 2;
        case 3: return 5;
        default:
            Matrix a, b;
            a = b = {
                {
                    {2,0,1},
                    {1,0,0},
                    {0,1,0}
                }
            };
            for(n-=4;n;n>>=1,a=a*a)
                if(n&1) b=b*a;
            return (b.ele[0][0]*5+b.ele[0][1]*2+b.ele[0][2])%mod;
        }
    }
};
class calculator3 : public calculator
{
private:
    int a[2][2], b[2][2];
public:
    int calc(int n)
    {
        memset(a, 0, sizeof(a));
        a[0][0] = 1;
        for(int i=1;i<=n;i++)
        {
            memset(b, 0, sizeof(b));
            (b[1][0] += a[0][0]) %= mod;  // [ ] + [⠖] = [⠖]
            (b[0][1] += a[0][0]) %= mod;  // [ ] + [⠦] = [⠦]
            (b[0][0] += a[0][0]) %= mod;  // [ ] + [⠆] = [⠆]
            (b[1][1] += a[0][0]) %= mod;  // [ ] + [⠒] + [⠤] = [⠶]
            (b[1][0] += a[0][1]) %= mod;  // [⠄] + [⠒] = [⠖]
            (b[1][1] += a[0][1]) %= mod;  // [⠄] + [⠲] = [⠶]
            (b[0][1] += a[1][0]) %= mod;  // [⠂] + [⠤] = [⠦]
            (b[1][1] += a[1][0]) %= mod;  // [⠂] + [⠴] = [⠶]
            (b[0][0] += a[1][1]) %= mod;  // [⠆] + [ ] = [⠆]
            memcpy(a, b, sizeof(a));
        }
        return a[0][0];
    }
};
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
    calculator* c = new calculator2;
    cout<<c->calc(n)<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
