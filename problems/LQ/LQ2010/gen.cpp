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
        if(_t<=8) fout<<rnd(1,30)(egn)<<' '<<rnd(1,30)(egn)<<endl;
        else if(_t==9) fout<<"29 30"<<endl;
        else fout<<"30 30"<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}
