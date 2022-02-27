#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 10;
double PHI = (1.000 + sqrt(5.000)) / 2.000;
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        int _t = 1e5;
        fout<<_t<<endl;
        while(_t--)
        {
            int p = rnd(1,100)(egn);
            if(p<=33)
            {
                int k = rnd(1,5e8)(egn);
                int n = floor(PHI * k);
                int m = k+n;
                fout<<m<<' '<<n<<endl;
            }
            else fout<<rnd(1,1e9)(egn)<<' '<<rnd(1,1e9)(egn)<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}