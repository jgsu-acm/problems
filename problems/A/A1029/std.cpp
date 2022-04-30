#include <iostream>
#include <cstring>
using namespace std;
const int mod = 998244353;
typedef long long ll;
struct Matrix
{
    ll ele[2][2];
    void init() { memset(ele, 0, sizeof(ele)); }
    Matrix operator*(Matrix& b)
    {
        Matrix res;
        res.init();
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    res.ele[i][j] = (res.ele[i][j] + ele[i][k]*b.ele[k][j])%mod;
        return res;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    switch(n)
    {
    case 1: cout<<2<<endl; break;
    case 2: cout<<3<<endl; break;
    default:
        Matrix a, b;
        a = b = {
            {
                {1,1},
                {1,0},
            }
        };
        for(n-=3;n;n>>=1,a=a*a)
            if(n&1) b=b*a;
        cout<<(b.ele[0][0]*3+b.ele[0][1]*2)%mod<<endl;
    }
    return 0;
}
