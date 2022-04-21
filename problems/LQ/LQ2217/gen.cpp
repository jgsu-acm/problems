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
        switch(_t)
        {
        case 1: fout<<1<<endl; break;
        case 2: fout<<2<<endl; break;
        default: fout<<int(1e7-(10-_t))<<endl; break;
        }
        // ==============================
        fout.close();
    }
    return 0;
}
