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
            n = rnd(10,20)(egn);
            m = rnd(10,20)(egn);
            break;
        case 2:
            n = m = rnd(10,20)(egn);
            break;
        case 3:
            n = 20;
            m = 19;
            break;
        case 4:
            n = rnd(80,100)(egn);
            m = rnd(80,100)(egn);
            break;
        case 5:
            n = m = rnd(80,100)(egn);
            break;
        case 6: 
            n = 99;
            m = 100;
            break;
        case 7:
            n = 100;
            m = 99;
            break;
        case 8: case 9:
            n = 499;
            m = 500;
            break;
        case 10:
            n = 500;
            m = 499;
            break;
        }
        int k;
        switch(_t)
        {
        case 1: k = rnd(1e4,5e4)(egn); break;
        case 2: k = rnd(1e4,5e4)(egn); break;
        case 3: k = rnd(5e4,1e5)(egn); break;
        case 4: k = rnd(1e5,1e6)(egn); break;
        case 5: k = rnd(1e5,1e6)(egn); break;
        case 6: k = rnd(1e5,1e6)(egn); break;
        case 7: k = rnd(1e5,1e6)(egn); break;
        case 8: k = rnd(1e8,2e8)(egn); break;
        case 9: k = rnd(1e7,2e7)(egn); break;
        case 10: k = rnd(1e7,2e7)(egn); break;
        }
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
