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
        int n,m;
        switch(t)
        {
        case 1: n=rnd(1,200)(egn), m=rnd(1,200)(egn); break;
        case 2: n=m=200; break;
        case 3: n=rnd(1,2000)(egn), m=rnd(1,2000)(egn); break;
        case 4: n=m=2000; break;
        case 9: case 10: n=m=2e5; break;
        default: n=rnd(1e5,2e5)(egn), m=rnd(1e5,2e5)(egn);
        }
        fout<<n<<' '<<m<<endl;
        for(int i=0;i<n;i++)
            fout<<rnd(1,1e9)(egn)<<' ';
        fout<<endl;
        for(int i=0;i<m;i++)
            fout<<rnd(1,1e9)(egn)<<' '<<rnd(1,n)(egn)<<' '<<rnd(1,1e9)(egn)<<' '<<rnd(1,5e8)(egn)<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}
