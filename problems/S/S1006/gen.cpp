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
        int n = _t<=3?1000:1e5;
        int m = n-1;
        fout<<n<<' '<<m<<' '<<rnd(1,1e5)(egn)<<endl;
        generate_n(ostream_iterator<int>(fout, " "), n, []() { return rnd(1,1e5)(egn); });
        for(int i=0;i<m;i++)
        {
            int l=rnd(1,n)(egn), r=rnd(1,n)(egn);
            if(l>r) swap(l,r);
            fout<<l<<' '<<r<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}
