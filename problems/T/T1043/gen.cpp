#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef uniform_int_distribution<> rnd;
typedef uniform_int_distribution<ll> rndll;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 3;
// ==============================

// ==============================
int main(int argc, char const* argv[])
{
    for(int _t=1;_t<=CASES;_t++)
    {
        ofstream fout(to_string(_t)+".in");
        // ==============================
        auto osit = ostream_iterator<int>(fout, " ");
        if(_t==3)
        {
            int n=5e6, k=1e9;
            fout<<n<<' '<<k<<endl;
            generate_n(osit, n, []() { return 1; });
        }
        else
        {
            int n=5e6, k=rnd(1,1e9)(egn);
            fout<<n<<' '<<k<<endl;
            generate_n(osit, n, []() { return rnd(1,1e6)(egn); });
        }
        // ==============================
        fout.close();
    }
    return 0;
}
