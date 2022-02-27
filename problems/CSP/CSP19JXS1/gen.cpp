#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 100;
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        switch(t)
        {
        case 1: fout<<"14-31"<<endl; break;     // 1
        case 2: fout<<"00-00"<<endl; break;     // 2
        case 3: fout<<"24-31"<<endl; break;     // 2
        case 4: fout<<"66-66"<<endl; break;     // 2
        case 5: fout<<"44-31"<<endl; break;     // 2
        case 6: fout<<"99-31"<<endl; break;     // 2
        case 7: fout<<"11-31"<<endl; break;     // 1
        case 8: fout<<"24-31"<<endl; break;     // 2
        case 9: fout<<"24-31"<<endl; break;     // 2
        default: fout<<(char)(rnd(0,9)(egn)+'0')<<(char)(rnd(0,9)(egn)+'0')<<'-'<<(char)(rnd(0,9)(egn)+'0')<<(char)(rnd(0,9)(egn)+'0')<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}