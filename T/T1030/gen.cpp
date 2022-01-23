#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 10;
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        int n=500, m=500, e=5e4;
        fout<<n<<' '<<m<<' '<<e<<endl;
        for(int i=0;i<e;i++)
            fout<<rnd(1,n)(egn)<<' '<<rnd(1,n)(egn)<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}