#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 20;
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        int n, ar;
        switch(t)
        {
        case 1: fout<<1<<endl<<"12 "; break;
        case 2: fout<<2<<endl<<"1 2 "; break;
        case 3: fout<<2<<endl<<"1 1 "; break;
        case 4: fout<<2<<endl<<"2 3 "; break;
        case 5: fout<<3<<endl<<"9 5 3 "; break;
        case 6:
            n=rnd(1,100)(egn);
            fout<<n<<endl;
            for(int i=0;i<n;i++)
                fout<<rnd(1,100)(egn)<<' ';
            break;
        case 7:
            fout<<100<<endl;
            for(int i=0;i<100;i++) fout<<1<<' ';
            break;
        case 8:
            fout<<100<<endl;
            for(int i=0;i<100;i++)
                fout<<(i%2?1:100)<<' ';
            break;
        default:
            if(t<=14)
            {
                ar=1e5;
                if(t<=12) n = rnd(1, 3000)(egn);
                else n = 3000;
            }
            else
            {
                ar = 1e9;
                if(t<=18) n = rnd(1, 2e5)(egn);
                else n = 2e5;
            }
            fout<<n<<endl;
            for(int i=0;i<n;i++)
                fout<<rnd(1, ar)(egn)<<' ';
        }
        // ==============================
        fout.close();
    }
    return 0;
}