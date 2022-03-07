#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 10;
// ==============================

// ==============================
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        for(int i=0;i<5;i++)
        {
            int p = rnd(1,10)(egn);
            if(p<=4)
            {
                int x = rnd(1,9)(egn);
                int y = rnd(0,8)(egn);
                fout<<x<<y<<x<<y+1<<endl;
            }
            else fout<<rnd(1000,9999)(egn)<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}
