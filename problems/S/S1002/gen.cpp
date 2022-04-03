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
        if(_t<=3) fout<<rnd(1,1e3)(egn)<<' '<<rnd(1,1e3)(egn)<<endl;
        else if(_t<=6) fout<<rnd(1e3+1,1e6)(egn)<<' '<<rnd(1e3+1,1e6)(egn)<<endl;
        else fout<<rnd(1e6+1,1e9)(egn)<<' '<<rnd(1e6+1,1e9)(egn)<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}
