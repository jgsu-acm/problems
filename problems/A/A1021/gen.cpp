#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 10;
#include <numeric>
#include <vector>
#include <algorithm>
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        vector<int> v(1e5);
        iota(v.begin(), v.end(), 1);
        shuffle(v.begin(), v.end(), egn);
        fout<<v.size()<<endl;
        for(auto i : v) fout<<i<<' ';
        // ==============================
        fout.close();
    }
    return 0;
}