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
        a = rnd(5,10)(egn);
        b = rnd(5,10)(egn);
        t = 5*a+2*b;
        switch(_t)
        {
        case 1:
            n = t*rnd(1,1e4)(egn);
            break;
        case 2:
            n = t*rnd(1,1e4)(egn)+rnd(1,5)(egn)*a;
            break;
        case 3:
            n = t*rnd(1,1e4)(egn)+rnd(1,4)(egn)*a+rnd(1,a-1)(egn);
            break;
        case 4:
            n = t*rnd(1,1e4)(egn)+5*a+rnd(1,2)(egn)*b;
            break;
        case 5:
            n = t*rnd(1,1e4)(egn)+5*a+b+rnd(1,b-1)(egn);
            break;
        case 6:
            n = t*rndll(1e15, 5e15)(egn)+rnd(1,4)(egn)*a+rnd(1,a-1)(egn);
            break;
        case 7:
            n = t*rndll(1e15, 5e15)(egn)+5*a+b+rnd(1,b-1)(egn);
            break;
        case 8:
            n = t*rndll(1e15, 5e15)(egn)+5*a+b+rnd(1,b-1)(egn);
            break;
        case 9:
            n = t*rndll(1e15, 5e15)(egn)+rnd(1,4)(egn)*a+rnd(1,a-1)(egn);
            break;
        case 10:
            n = t*rndll(1e15, 5e15)(egn)+5*a+b+rnd(1,b-1)(egn);
            break;
        }
        fout<<a<<' '<<b<<' '<<n<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}
