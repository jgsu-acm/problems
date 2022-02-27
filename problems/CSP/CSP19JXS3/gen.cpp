#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 25;
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        int n,m,mx;
        if(t<=5) n=m=3, mx=10;
        else if(t<=8) n=rnd(4,20)(egn), m=rnd(4,20)(egn), mx=100;
        else if(t<=10) n=m=20, mx=100;
        else if(t<=14) n=rnd(21,300)(egn), m=rnd(21,300)(egn), mx=1000;
        else if(t<=16) n=m=300, mx=1000;
        else if(t<=23) n=rnd(301,3e5)(egn), m=rnd(301,3e5)(egn), mx=1e5;
        else n=m=3e5, mx=1e5;
        fout<<n<<' '<<m<<endl;
        for(int i=0;i<n;i++) fout<<rnd(1,mx)(egn)<<' ';
        fout<<endl;
        for(int i=0;i<m;i++) fout<<rnd(1,mx)(egn)<<' ';
        fout<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}