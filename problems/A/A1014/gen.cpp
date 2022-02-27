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
        int _t = 1e5;
        fout<<_t<<endl;
        while(_t--)
        {
            int a,b,c;
            do 
            {
                a=rnd(1,1e4)(egn);
                b=rnd(1,1e4)(egn);
                c=rnd(1,1e4)(egn);
            } while(!(a+b>c&&a+c>b&&b+c>a));
            fout<<a<<' '<<b<<' '<<c<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}