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
        int n = 1e5;
        fout<<n<<endl;
        vector<int> v(n);
        iota(v.begin(), v.end(), 1);
        random_shuffle(v.begin(), v.end());
        for(auto i : v) fout<<i<<' ';
        fout<<endl;
        random_shuffle(v.begin(), v.end());
        for(auto i : v) fout<<i<<' ';
        fout<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}