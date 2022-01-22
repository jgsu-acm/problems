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
        int _t=10;
        fout<<_t<<endl;
        while(_t--)
        {
            int n = 1e4;
            fout<<n<<endl;
            int x = 0;
            for(int i=1;i<n;i++)
            {
                int tmp = rnd(1,1e4)(egn);
                x ^= tmp;
                fout<<tmp<<' ';
            }
            int p = rnd(1,100)(egn);
            if(p<=50) fout<<x<<endl;
            else fout<<rnd(1,1e4)(egn)<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}