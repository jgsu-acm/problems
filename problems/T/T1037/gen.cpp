#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 10;
// ==============================

// ==============================
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        int _t = 1e3;
        fout<<_t<<endl;
        for(int i=0;i<_t;i++)
            fout<<rnd(1,2e8)(egn)<<' ';
        // ==============================
        fout.close();
    }
    return 0;
}