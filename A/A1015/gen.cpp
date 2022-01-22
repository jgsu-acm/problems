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
        int n=1000;
        fout<<n<<endl;
        for(int i=2;i<=n;i++)
            fout<<i<<' '<<rnd(1,i-1)(egn)<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}