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
        int n,m;
        if(t<=3) n=m=1000;
        else if(t<=6) n=m=5000;
        else n=m=1e5;
        fout<<n<<' '<<m<<endl;
        for(int i=0;i<m;i++)
            fout<<rnd(0,1)(egn)<<' '<<rnd(1,n)(egn)<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}