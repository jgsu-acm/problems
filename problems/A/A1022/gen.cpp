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
        int W, n;
        if(t<=5)
        {
            do W=rnd(1,1e7)(egn), n=rnd(1,1e4)(egn);
            while((long long)W*n>2e8);
        }
        else if(t<=7)
        {
            n=1e4;
            W=rnd(1,2e4)(egn);
        }
        else W=1e7, n=200;
        fout<<W<<endl<<n<<endl;
        for(int i=0;i<n;i++)
            fout<<rnd(W/2,W)(egn)<<' ';
        // ==============================
        fout.close();
    }
    return 0;
}