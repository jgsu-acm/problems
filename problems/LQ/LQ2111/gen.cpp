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
        vector<vector<int>> v;
        int sum = 0;
        while(true)
        {
            int n = rnd(1,500)(egn);
            if(sum+n>2e5) break;
            sum += n;
            vector<int> vt;
            for(int i=0;i<n;i++)
                vt.push_back(rnd(0,(1<<20))(egn));
            v.emplace_back(vt);
        }
        fout<<v.size()<<endl;
        for(auto& i : v)
        {
            fout<<i.size()<<' ';
            for(auto j : i)
                fout<<j<<' ';
            fout<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}