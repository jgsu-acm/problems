#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <sstream>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 20;
// ==============================

// ==============================
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        auto special = []()
        {
            stringstream ss;
            int x = rnd(1,9)(egn);
            int y = rnd(0,8)(egn);
            ss<<x<<y<<x<<y+1;
            return ss.str();
        };
        int k = (t-1)/4+1;
        vector<string> v;
        v.emplace_back(special());
        for(int i=0;i<5-k;i++)
        {
            string s;
            do s = to_string(rnd(1000,9999)(egn)); while(s[0]==s[2]&&s[1]+1==s[3]);
            v.emplace_back(s);
        }
        for(int i=0;i<k-1;i++) v.emplace_back(special());
        for(auto&& s : v) fout<<s<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}
