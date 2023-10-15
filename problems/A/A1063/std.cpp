#include <iostream>
using namespace std;
class mint
{
    const static int mod = 998244353;
    long long x;
    void norm() { x = (x%mod+mod)%mod; }
public:
    mint() : x(0) {}
    mint(long long x) : x(x) { norm(); }
    friend mint operator^(mint lhs, long long rhs)
    {
        mint res = 1;
        for(;rhs;rhs>>=1,lhs=lhs*lhs) if(rhs&1) res = res*lhs;
        return res;
    }
    mint operator~() { return (*this)^(mod-2); }
    friend mint operator+(mint lhs, mint rhs) { return lhs.x+rhs.x; }
    friend mint operator-(mint lhs, mint rhs) { return lhs.x-rhs.x; }
    friend mint operator*(mint lhs, mint rhs) { return lhs.x*rhs.x; }
    friend mint operator/(mint lhs, mint rhs) { return lhs*(~rhs); }
    friend istream& operator>>(istream& is, mint& rhs) { is>>rhs.x; rhs.norm(); return is; }
    friend ostream& operator<<(ostream& os, mint rhs) { return os<<rhs.x; }
};
const int maxn = 2e5+5;
mint h[maxn];
int main()
{
    int n;
    cin>>n;
    h[0] = 1;
    for(int i=1;i<=2*n-1;i++) h[i] = h[i-1]*(4*i-2)/(i+1);
    mint sum=0, mul=2;
    for(int i=0;i<n;i++)
    {
        sum = sum+h[i]/mul;
        mul = mul*4;
    }
    cout<<sum<<endl;
    return 0;
}
