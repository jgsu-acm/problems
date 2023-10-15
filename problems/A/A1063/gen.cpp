#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef uniform_int_distribution<> rnd;
typedef uniform_int_distribution<ll> rndll;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 20;
// ==============================

// ==============================
int main(int argc, char const* argv[])
{
    for(int _t=1;_t<=CASES;_t++)
    {
        ofstream fout(to_string(_t)+".in");
        // ==============================
        if(_t<=2) fout<<_t+1<<endl;
        else if(_t<=10) fout<<_t+(1000-10)<<endl;
        else fout<<_t+(100000-20)<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}
