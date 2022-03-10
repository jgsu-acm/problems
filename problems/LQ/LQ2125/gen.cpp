#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 100;
// ==============================

// ==============================
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        if(t<=5)
        {
            switch(t)
            {
            case 1: fout<<1<<' '<<1<<' '<<1<<endl; break;
            case 2: fout<<2<<' '<<2<<' '<<1<<endl; break;
            case 3: fout<<5<<' '<<5<<' '<<1<<endl; break;
            default: fout<<rnd(1,6)(egn)<<' '<<rnd(1,100)(egn)<<' '<<1<<endl; break;
            }
        }
        else if(t<=15)
        {
            switch(t)
            {
            case 6: fout<<1<<' '<<1<<' '<<2<<endl; break;
            case 7: fout<<2<<' '<<2<<' '<<2<<endl; break;
            case 8: fout<<5<<' '<<5<<' '<<2<<endl; break;
            default: fout<<rnd(1,6)(egn)<<' '<<rnd(1,100)(egn)<<' '<<2<<endl; break;
            }
        }
        else if(t<=25)
        {
            fout<<1<<' '<<rnd(1,100)(egn)<<' '<<rnd(1,20)(egn)<<endl;
        }
        else if(t<=45)
        {
            fout<<rnd(1,6)(egn)<<' '<<rnd(1,6)(egn)<<' '<<rnd(1,5)(egn)<<endl;
        }
        else if(t<=70)
        {
            fout<<rnd(1,3)(egn)<<' '<<rnd(7,20)(egn)<<' '<<rnd(6,12)(egn)<<endl;
        }
        else 
        {
            fout<<rnd(4,6)(egn)<<' '<<rnd(21,100)(egn)<<' '<<rnd(13,20)(egn)<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}
