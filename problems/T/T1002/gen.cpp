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
        for(int i=1;i<=n;i++)
            fout<<rnd(1,100)(egn)<<' ';
        for(int i=1;i<=m;i++)
        {
            int f = rnd(1,100)(egn),opt;
            if(f<=15) opt=1;
            else if(f<=45) opt=2;
            else opt=3;
            fout<<opt<<' ';
            switch(opt)
            {
            case 1:
                fout<<rnd(1,n)(egn)<<endl;
                break;
            case 2:
                fout<<rnd(1,n)(egn)<<' '<<rnd(1,100)(egn)<<endl;
                break;
            case 3:
                int l=rnd(1,n)(egn);
                int r=rnd(1,n)(egn);
                if(l>r) swap(l,r);
                fout<<l<<' '<<r<<endl;
                break;
            }
        }
        // ==============================
        fout.close();
    }
    return 0;
}