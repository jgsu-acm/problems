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
        int n, x;
        switch(t)
        {
        case 1: n=x=5; break;
        case 2: n=x=10; break;
        case 3: n=100; x=50; break;
        case 4: n=200; x=100; break;
        case 5: n=1000; x=5e4; break;
        case 6: n=2000; x=1e5; break;
        case 7: n=3000; x=1e5; break;
        case 8: n=3e5; x=1e7; break;
        case 9: n=5e5; x=1e8; break;
        case 10: n=5e5; x=1e9; break;
        }
        fout<<n<<endl;
        for(int i=0;i<n;i++) fout<<rnd(1,x)(egn)<<' ';
        fout<<endl;
        for(int i=0;i<n;i++) fout<<rnd(1,x)(egn)<<' ';
        fout<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}