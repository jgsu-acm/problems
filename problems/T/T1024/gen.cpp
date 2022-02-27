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
        int n = 1e3;
        fout<<n<<' '<<n<<endl;
        vector<int> v1, v2;
        for(int i=0;i<n;i++)
        {
            v1.push_back(rnd(1,10)(egn));
            v2.push_back(rnd(1,10)(egn));
        }
        for(auto i : v1) fout<<i<<' ';
        fout<<endl;
        for(auto i : v2) fout<<i<<' ';
        fout<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}