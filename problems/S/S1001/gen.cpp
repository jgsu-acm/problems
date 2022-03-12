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
        if(t<=3)
        {
            int n = rnd(1,9)(egn);
            fout<<n<<' '<<rnd(1,n*4)(egn)<<endl;
        }
        else fout<<9<<' '<<rnd(1,36)(egn)<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}
