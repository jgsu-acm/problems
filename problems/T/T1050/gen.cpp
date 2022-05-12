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
        int m = n-1;
        fout<<n<<' '<<m<<endl;
        generate_n(ostream_iterator<int>(fout, " "), n, []() { return rnd(-1e9, 1e9)(egn); });
        fout<<endl;
        for(int i=0;i<m;i++)
        {
            int l = rnd(1,n)(egn);
            int r = rnd(1,n)(egn);
            if(l>r) swap(l,r);
            int k = rnd(1,r-l+1)(egn);
            fout<<l<<' '<<r<<' '<<k<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}
