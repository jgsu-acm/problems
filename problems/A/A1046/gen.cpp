#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef uniform_int_distribution<> rnd;
typedef uniform_int_distribution<ll> rndll;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 20;
// ==============================

// ==============================
int main(int argc, char const* argv[])
{
    for(int _t=1;_t<=CASES;_t++)
    {
        ofstream fout(to_string(_t)+".in");
        // ==============================
        if(_t==1) fout<<1<<endl<<1<<endl;
        else if(_t==2) fout<<2<<endl<<1<<' '<<2<<endl;
        else
        {
            int n, t;
            if(_t<=8)
            {
                n = 10;
                t = rnd(1, _t<=4?10:1e8)(egn);
            }
            else
            {
                n = 1e5;
                t = rnd(1, 1e4)(egn);
            }
            fout<<n<<endl;
            int s = n*t;
            vector<int> v(n-1);
            for(int i=0;i<n-1;i++) v[i] = rnd(0,s)(egn);
            sort(v.begin(), v.end());
            int last = 0;
            for(int i=0;i<n-1;i++)
            {
                fout<<v[i]-last<<' ';
                last = v[i];
            }
            fout<<s-last<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}
