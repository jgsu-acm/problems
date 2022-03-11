#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 20;
// ==============================

// ==============================
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        int maxn, _t;
        switch(t)
        {
        case 1: maxn=10, _t=10; break;
        case 2: maxn=10, _t=1e5; break;
        case 3: maxn=20, _t=20; break;
        case 4: maxn=20, _t=1e5; break;
        case 5: maxn=1000, _t=10; break;
        case 6: maxn=1000, _t=20; break;
        case 7: maxn=1e5, _t=10; break;
        case 8: maxn=1e5, _t=20; break;
        default: maxn=1e6, _t=1e5; break;
        }
        fout<<_t<<endl;
        for(int i=0;i<_t;i++)
            fout<<rnd(1,maxn)(egn)<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}
