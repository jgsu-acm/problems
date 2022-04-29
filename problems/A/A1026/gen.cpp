#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef uniform_int_distribution<> rnd;
typedef uniform_int_distribution<ll> rndll;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 10;
// ==============================
string random_string(size_t length)
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[rand() % max_index];
    };
    string str(length, 0);
    generate_n(str.begin(), length, randchar);
    return str;
}
set<string> st1;
set<double> st2;
// ==============================
int main(int argc, char const* argv[])
{
    for(int _t=1;_t<=CASES;_t++)
    {
        ofstream fout(to_string(_t)+".in");
        // ==============================
        int n = 1e5;
        fout<<n<<endl;
        for(int i=0;i<n;i++)
        {
            string s;
            do s = random_string(rnd(1,20)(egn));
            while(st1.find(s)!=st1.end());
            st1.insert(s);
            double g1 = rndf(-20,20)(egn);
            double g2 = rndf(-20,20)(egn);
            double g3 = rndf(-20,20)(egn);
            double g4 = rndf(-20,20)(egn);
            double spr = g1+g2+g3+g4;
            while(st2.find(spr)!=st2.end()) g4 = rndf(-20,20)(egn), spr = g1+g2+g3+g4;
            st2.insert(spr);
            fout<<s<<' '<<g1<<' '<<g2<<' '<<g3<<' '<<g4<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}
