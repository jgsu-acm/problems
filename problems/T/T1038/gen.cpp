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
        int q = 1e6;
        fout<<q<<endl;
        generate_n(ostream_iterator<int>(fout, "\n"), q, []() { return rnd(1,5761450)(egn); });
        // ==============================
        fout.close();
    }
    return 0;
}
