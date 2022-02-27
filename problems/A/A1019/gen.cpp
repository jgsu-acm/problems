//! 注意：（因为懒）数据并没有保证一定有解，只不过无解的情况出现的概率很小，基本生成不出来
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
        int n = 1e6;
        fout<<n<<endl;
        for(int i=0;i<n;i++)
            fout<<rnd(1,1e9)(egn)<<' ';
        // ==============================
        fout.close();
    }
    return 0;
}