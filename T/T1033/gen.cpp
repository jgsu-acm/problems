#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 10;
#include <cmath>
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        int n=1e6, k;
        if(t<=3) k=n/3;
        else if(t<=6) k=sqrt(n);
        else if(t<=9) k=rnd(1, n)(egn);
        else k=1;
        fout<<n<<' '<<k<<endl;
        for(int i=1;i<=n;i++) fout<<rnd(1,1e9)(egn)<<' ';
        fout<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}
