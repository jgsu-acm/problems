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
        int n,m,w;
        if(t<=3) n=10,m=10,w=10;
        else if(t<=6) n=30,m=20,w=30;
        else n=100,m=50,w=100;
        fout<<n<<' '<<m<<endl;
        for(int i=0;i<n;i++)
            fout<<rnd(1,w)(egn)<<' ';
        // ==============================
        fout.close();
    }
    return 0;
}