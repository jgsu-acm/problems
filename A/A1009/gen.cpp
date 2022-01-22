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
        n=m=1e5;
        fout<<n<<' '<<m<<endl;
        for(int i=0;i<n;i++)
            fout<<rnd(1,550)(egn)<<' ';
        fout<<endl;
        while(m--)
        {
            int l=rnd(1,n)(egn), r=rnd(1,n)(egn);
            if(l>r) swap(l,r);
            fout<<l<<' '<<r<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}