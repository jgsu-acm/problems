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
        int n,m;
        if(_t<=3) n=1e4, m=1e3;
        else n=1e5, m=1e4;
        fout<<n<<endl;
        generate_n(ostream_iterator<int>(fout, " "), n, []() { return rnd(-1e9,1e9)(egn); });
        fout<<endl;
        fout<<m<<endl;
        for(int i=0;i<m;i++)
        {
            int opt = rnd(0,1)(egn);
            if(opt) fout<<"add"<<' '<<rnd(-1e9,1e9)(egn)<<endl;
            else fout<<"mid"<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}
