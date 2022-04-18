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
            int n = 1000;
            int k = rnd(1,1e8)(egn);
            fout<<n<<' '<<k<<endl;
            generate_n(ostream_iterator<int>(fout, " "), n, []() { return rnd(1,1e4)(egn); });
        }
        else 
        {
            int n = 1e5;
            ll k;
            if(_t>=9) k = 1e10;
            else k = rndll(1,1e10)(egn);
            fout<<n<<' '<<k<<endl;
            if(_t==10) generate_n(ostream_iterator<int>(fout, " "), n, []() { return rnd(1,100)(egn); });
            else generate_n(ostream_iterator<int>(fout, " "), n, []() { return rnd(1,1e9)(egn); });
        }
        // ==============================
        fout.close();
    }
    return 0;
}
