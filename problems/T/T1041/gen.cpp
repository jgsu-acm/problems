#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef uniform_int_distribution<> rnd;
typedef uniform_int_distribution<ll> rndll;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 25;
// ==============================
ll phi(ll x)
{
    ll res = x;
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            res = res/i*(i-1);
            while(x%i==0) x/=i;
        }
    }
    if(x>1) res = res/x*(x-1);
    return res;
}
// ==============================
int main(int argc, char const* argv[])
{
    for(int _t=1;_t<=CASES;_t++)
    {
        ofstream fout(to_string(_t)+".in");
        // ==============================
        int a = rnd(1,1e9)(egn);
        int p = rnd(1,1e9)(egn);
        if(_t>15)
        {
            while(__gcd(a,p)==1)
            {
                a = rnd(1,1e9)(egn);
                p = rnd(1,1e9)(egn);
            }
        }
        string b;
        if(_t<=5)
        {
            int tmp = rnd(1,phi(p))(egn);
            b = to_string(tmp);
        }
        else generate_n(inserter(b, b.begin()), 1e7-1, []() { return char(rnd('0','9')(egn)); });
        b = char(rnd('1','9')(egn)) + b;
        fout<<a<<' '<<b<<' '<<p<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}
