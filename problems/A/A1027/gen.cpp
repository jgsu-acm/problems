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
        int n = 2e5;
        fout<<n<<endl;
        for(int i=0;i<n;i++) fout<<rnd(1,1e3)(egn)<<' '<<rnd(1,1e3)(egn)<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}
