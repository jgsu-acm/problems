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
        int n;
        if(t<=3) n=20;
        else n=1e5;
        fout<<n<<endl;
        for(int i=1;i<n;i++)
            fout<<rnd(1,i)(egn)<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}