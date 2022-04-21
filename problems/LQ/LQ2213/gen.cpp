#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef uniform_int_distribution<> rnd;
typedef uniform_int_distribution<ll> rndll;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 10;
// ==============================

// ==============================
int main(int argc, char const* argv[])
{
    for(int _t=1;_t<=CASES;_t++)
    {
        ofstream fout(to_string(_t)+".in");
        // ==============================
        ll a,b,n,t;
        if(_t<=5)
        {
            a = rnd(1,1e4)(egn);
            b = rnd(1,1e4)(egn);
        }
        else
        {
            a = rndll(1,1e16)(egn);
            b = rndll(1,1e16)(egn);
        }
        t = 5*a+2*b;
        switch((_t-1)%5)
        {
        case 0:
            n = t*rnd(1,10)(egn);
            break;
        case 1:
            n = t*rnd(1,10)(egn)+rnd(1,5)(egn)*a;
            break;
        case 2:
            n = t*rnd(1,10)(egn)+rnd(1,4)(egn)*a+rnd(1,a-1)(egn);
            break;
        case 3:
            n = t*rnd(1,10)(egn)+5*a+rnd(1,2)(egn)*b;
            break;
        case 4:
            n = t*rnd(1,10)(egn)+5*a+b+rnd(1,b-1)(egn);
            break;
        }
        fout<<a<<' '<<b<<' '<<n<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}
