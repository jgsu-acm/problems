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
        if(_t<=3)
        {
            n = 20;
            m = 100;
        }
        else if(_t<=5)
        {
            n = 100;
            m = 1000;
        }
        else if(_t<=7)
        {
            n = 1000;
            m = 10000;
        }
        else
        {
            n = 10000;
            m = 100000;
        }
        fout<<n<<' '<<m<<endl;
        for(int i=0;i<m;i++)
        {
            int opt = rnd(1,2)(egn);
            if(opt==1)
            {
                fout<<opt<<' '<<rnd(1,n)(egn)<<' '<<rnd(1,n)(egn)<<endl;
            }
            else 
            {
                fout<<opt<<' '<<rnd(1,n)(egn)<<' '<<rnd(1,100)(egn)<<endl;
            }
        }
        // ==============================
        fout.close();
    }
    return 0;
}
