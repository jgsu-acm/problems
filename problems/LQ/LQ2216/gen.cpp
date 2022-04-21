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
        switch(_t)
        {
        case 1:
            n = rnd(1,20)(egn);
            m = rnd(1,20)(egn);
            break;
        case 2:
            n = m = rnd(1,20)(egn);
            break;
        case 3:
            n = 20;
            m = 19;
            break;
        case 4:
            n = rnd(21,100)(egn);
            m = rnd(21,100)(egn);
            break;
        case 5:
            n = m = rnd(21,200)(egn);
            break;
        case 6: case 7:
            n = 200;
            m = 199;
            break;
        case 8:
            n = m = rnd(201,500)(egn);
            break;
        case 9:
            n = 499;
            m = 500;
            break;
        case 10:
            n = 500;
            m = 499;
            break;
        }
        int k;
        if(_t==2||_t==6||_t==9) k = 2.5e8;
        else k = rnd(1,1e5)(egn);
        fout<<n<<' '<<m<<' '<<k<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                fout<<rnd(0,1000)(egn)<<' ';
            fout<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}
