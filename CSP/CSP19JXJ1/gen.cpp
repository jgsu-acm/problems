#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 50;
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        int a,b,c;
        if(t<=15)
        {
            a = rnd(1,100)(egn);
            b = rnd(1,100)(egn);
            c = rnd(1,100)(egn);
        }
        else if(t<=40)
        {
            a = rnd(101,1e4)(egn);
            b = rnd(101,1e4)(egn);
            c = rnd(101,1e4)(egn);
        }
        else 
        {
            a = rnd(1e4,1e9)(egn);
            b = rnd(1e4,1e9)(egn);
            c = rnd(1e4,1e9)(egn);
        }
        fout<<a<<' '<<b<<' '<<c<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}