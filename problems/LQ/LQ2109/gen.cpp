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
        if(t==1) fout<<1<<endl;
        else if(t==2) fout<<10<<endl;
        else if(t==10) fout<<(int)1e9<<endl;
        else if(t<=8) fout<<rnd(11, 1e9)(egn)<<endl;
        else fout<<rnd(5e8, 1e9)(egn)<<endl;;
        // ==============================
        fout.close();
    }
    return 0;
}