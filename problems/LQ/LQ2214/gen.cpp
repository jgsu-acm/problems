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
        if(_t<=3)
        {
            fout<<_t*3<<endl;
        }
        else 
        {
            fout<<rnd(11,10000)(egn)<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}
