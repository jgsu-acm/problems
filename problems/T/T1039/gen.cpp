#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef uniform_int_distribution<> rnd;
typedef uniform_int_distribution<ll> rndll;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 10;
// ==============================

// ==============================
int main(int argc, char const* argv[])
{
    for(int _t=1;_t<=CASES;_t++)
    {
        ofstream fout(to_string(_t)+".in");
        // ==============================
        int q = 200;
        fout<<q<<endl;
        unordered_set<ll> s;
        while(s.size()!=q)
            s.insert(rndll(1,1e12)(egn));
        for(auto i : s) fout<<i<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}
