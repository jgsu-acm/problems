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
        int n=1e5, m=2e6;
        fout<<n<<' '<<m<<endl;
        for(int i=0;i<n;i++) fout<<rnd(0,1e9)(egn)<<' ';
        while(m--)
        {
            int l,r;
            if(t<=5)
            {
                l = rnd(1,n)(egn);
                r = rnd(1,n)(egn);
                if(l>r) swap(l,r);
            }
            else 
            {
                do { l = rnd(1,n)(egn), r = rnd(1,n)(egn); }
                while(l>r || r-l<n/2);
            }
            fout<<l<<' '<<r<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}
