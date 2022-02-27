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
        int n;
        if(t<=4)
        {
            if(t==4) n=8;
            else n = rnd(1,8)(egn);
        }
        else if(t<=10)
        {
            if(t>=9) n=20;
            else n=rnd(9,20)(egn);
        }
        else
        {
            if(t==16||t==20) n=2000;
            else n=rnd(21,2000)(egn);
        }
        fout<<n<<endl;
        if(t<=16) for(int i=0;i<n;i++) fout<<((char)(rnd(0,1)(egn)+'a'));
        else 
        {
            int p = rnd(1,100)(egn);
            if(p>30) egn = mt19937(time(nullptr)+p);
            for(int i=0;i<n;i++) fout<<((char)(rnd(0,25)(egn)+'a'));
        }
        // ==============================
        fout.close();
    }
    return 0;
}