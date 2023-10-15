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
        if(_t==1) fout<<"1 100000"<<endl;
        else if(_t==2)
        {
            int r=1e9, l=r-1e5;
            fout<<l<<' '<<r<<endl;
        }
        else if(_t==3) fout<<"500 677"<<endl;
        else if(_t==4) fout<<"50 100"<<endl;
        else if(_t==5) fout<<"257 4357"<<endl;
        else if(_t==6) fout<<"176401 276401"<<endl;
        else if(_t==7)
        {
            ll r=8000600000, l=r-1e5;
            fout<<l<<' '<<r<<endl;
        }
        else if(_t==8)
        {
            ll r=9999300000, l=r-1e5;
            fout<<l<<' '<<r<<endl;
        }
        else if(_t==9)
        {
            ll l=1, r=1e9;
            fout<<l<<' '<<r<<endl;
        }
        else if(_t==10)
        {
            ll l=1e9, r=2e9;
            fout<<l<<' '<<r<<endl;
        }
        else if(_t<=12)
        {
            ll l=rndll(2,1e9-1)(egn), r=l+1e9;
            fout<<l<<' '<<r<<endl;
        }
        else
        {
            int k = _t-11;
            ll r=(k+1)*1e11, l=r-1e9;
            fout<<l<<' '<<r<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}
