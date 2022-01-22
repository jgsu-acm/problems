#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 50;
int main(int argc, char const* argv[])
{
    const int maxw = 10000;
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        int n=100, W=rnd(maxw/2, maxw)(egn);
        fout<<n<<' '<<W<<endl;
        for(int i=0;i<n;i++)
            fout<<rnd(1,100)(egn)<<' '<<rnd(1,100)(egn)<<' '<<rnd(1,100)(egn)<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}