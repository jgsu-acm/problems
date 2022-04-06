#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef uniform_int_distribution<> rnd;
typedef uniform_int_distribution<ll> rndll;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 25;
// ==============================

// ==============================
int main(int argc, char const* argv[])
{
    for(int _t=1;_t<=CASES;_t++)
    {
        ofstream fout(to_string(_t)+".in");
        // ==============================
        int a = rnd(1,1e9)(egn);
        int p = rnd(1,1e9)(egn);
        string b;
        generate_n(inserter(b, b.begin()), 2e7-1, []() { return char(rnd('0','9')(egn)); });
        b = char(rnd('0','9')(egn)) + b;
        fout<<a<<' '<<b<<' '<<p<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}
