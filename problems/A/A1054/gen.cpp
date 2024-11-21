#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef uniform_int_distribution<> rnd;
typedef uniform_int_distribution<ll> rndll;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 10;
// ==============================
auto rndx() { return rnd(-20, 20)(egn); }
auto rndo() { return rnd(0,1)(egn)==0?1:-1; }
// ==============================
int main(int argc, char const* argv[])
{
    for(int _t=1;_t<=CASES;_t++)
    {
        ofstream fout(to_string(_t)+".in");
        // ==============================
        auto f = [&]()
        {
            for(int j=1;j<=5;j++)
                for(int i=-100;i<=100;i++)
                    fout<<i<<' '<<j<<'\n';
        };
        auto one = [&]() { fout<<1005<<'\n'; f(); };
        auto two = [&]() { fout<<2010<<'\n'; f(); f(); };
        auto b_pos = [&]()
        {
            fout<<rndx()<<' '<<1<<' '<<rndx()<<'\n';
            fout<<1<<' '<<rndx()<<' '<<1<<'\n';
            fout<<rndx()<<' '<<1<<' '<<rndx()<<'\n';
        };
        auto b_neg = [&]()
        {
            fout<<rndx()<<' '<<-1<<' '<<rndx()<<'\n';
            fout<<-1<<' '<<rndx()<<' '<<-1<<'\n';
            fout<<rndx()<<' '<<-1<<' '<<rndx()<<'\n';
        };
        auto b_rnd = [&]()
        {
            fout<<rndx()<<' '<<rndo()<<' '<<rndx()<<'\n';
            fout<<rndo()<<' '<<rndx()<<' '<<rndo()<<'\n';
            fout<<rndx()<<' '<<rndo()<<' '<<rndx()<<'\n';
        };
        int t;
        if(_t<=0.3*CASES) t = 1;
        else t = 200;
        fout<<t<<'\n';
        while(t--)
        {
            switch(_t)
            {
            case 1:
                b_pos();
                one();
                break;
            case 2:
                b_neg();
                one();
                break;
            case 3:
                b_rnd();
                one();
                break;
            case 4: case 5:
                b_pos();
                two();
                break;
            case 6: case 7:
                b_neg();
                two();
                break;
            default:
                b_rnd();
                two();
                break;
            }
        }
        // ==============================
        fout.flush();
        fout.close();
    }
    return 0;
}
