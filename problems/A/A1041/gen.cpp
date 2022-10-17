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
        if(_t==1)
        {
            int t = 1000;
            fout<<t<<endl;
            for(int i=1;i<=t;i++) fout<<i<<endl;
        }
        else if(_t<=3)
        {
            int t = 1e5;
            fout<<t<<endl;
            for(int i=1;i<=t;i++) fout<<rnd(1001,1e9)(egn)<<endl;
        }
        else
        {
            int t = 1e5;
            fout<<t<<endl;
            for(int i=1;i<=t;i++) fout<<rndll(1e9+1,1e18)(egn)<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}
