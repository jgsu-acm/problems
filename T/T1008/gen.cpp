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
        int n,m,p,q;
        n=m=2000;
        p=rnd(n/2,n)(egn);
        q=rnd(m/2,m)(egn);
        fout<<n<<' '<<m<<' '<<p<<' '<<q<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                fout<<rnd(-100,100)(egn)<<' ';
            fout<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}