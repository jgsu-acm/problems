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
        if(_t<=6) fout<<10-_t+1<<endl;
        else if(_t<=10) fout<<100000-_t+1<<endl;
        else fout<<1000000000-_t+1<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}
