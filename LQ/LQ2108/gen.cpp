#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <algorithm>
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
        int n;
        if(t<=5) n=15;
        else n=100;
        fout<<n<<endl;
        int sum;
        do sum = rnd(1,1e5)(egn);
        while(sum<n);
        vector<int> v;
        for(int i=1;i<n;i++)
            v.push_back(rnd(1,sum)(egn));
        v.push_back(0);
        v.push_back(sum);
        sort(v.begin(), v.end());
        vector<int> v2;
        for(int i=1;i<v.size();i++) v2.push_back(v[i]-v[i-1]);
        sort(v2.begin(), v2.end());
        for(auto i : v2) fout<<i<<' ';
        // ==============================
        fout.close();
    }
    return 0;
}