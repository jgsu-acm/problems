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
        switch(_t)
        {
        case 1: case 2:
            fout<<200<<'\n';
            for(int o=0;o<200;o++)
            {
                fout<<rndx()<<' '<<1<<' '<<rndx()<<'\n';
                fout<<1<<' '<<rndx()<<' '<<1<<'\n';
                fout<<rndx()<<' '<<1<<' '<<rndx()<<'\n';
                fout<<1000<<'\n';
                for(int j=1;j<=5;j++)
                    for(int i=-100;i<=100;i++)
                        fout<<i<<' '<<j<<'\n';
            }
            break;
        case 3: case 4:
            fout<<200<<'\n';
            for(int o=0;o<200;o++)
            {
                fout<<rndx()<<' '<<-1<<' '<<rndx()<<'\n';
                fout<<-1<<' '<<rndx()<<' '<<-1<<'\n';
                fout<<rndx()<<' '<<-1<<' '<<rndx()<<'\n';
                fout<<1000<<'\n';
                for(int j=1;j<=5;j++)
                    for(int i=-100;i<=100;i++)
                        fout<<i<<' '<<j<<'\n';
            }
            break;
        default:
            fout<<200<<'\n';
            for(int o=0;o<200;o++)
            {
                fout<<rndx()<<' '<<rndo()<<' '<<rndx()<<'\n';
                fout<<rndo()<<' '<<rndx()<<' '<<rndo()<<'\n';
                fout<<rndx()<<' '<<rndo()<<' '<<rndx()<<'\n';
                fout<<1000<<'\n';
                for(int j=1;j<=5;j++)
                    for(int i=-100;i<=100;i++)
                        fout<<i<<' '<<j<<'\n';
            }
            break;
        }
        // ==============================
        fout.flush();
        fout.close();
    }
    return 0;
}
