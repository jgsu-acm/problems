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
        int n = 1e6;
        int m = n-1;
        fout<<n<<' '<<m<<endl;
        generate_n(ostream_iterator<int>(fout, " "), n, []() { return rnd(-1e9,1e9)(egn); });
        fout<<endl;
        for(int i=1;i<=m;i++)
        {
            int opt = rnd(1,2)(egn);
            if(opt==1) fout<<rnd(0,i-1)(egn)<<' '<<1<<' '<<rnd(1,n)(egn)<<' '<<rnd(-1e9,1e9)(egn)<<endl;
            else fout<<rnd(0,i-1)(egn)<<' '<<2<<' '<<rnd(1,n)(egn)<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}
