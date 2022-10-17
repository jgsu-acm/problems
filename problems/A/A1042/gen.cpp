#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef uniform_int_distribution<> rnd;
typedef uniform_int_distribution<ll> rndll;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 4;
// ==============================
char rndlower() { return rnd('a', 'z')(egn); }
char rndupper() { return rnd('A', 'Z')(egn); }
string rndelement()
{
    string s;
    s.push_back(rndupper());
    s.push_back(rndlower());
    return s;
}
// ==============================
int main(int argc, char const* argv[])
{
    for(int _t=1;_t<=CASES;_t++)
    {
        ofstream fout(to_string(_t)+".in");
        // ==============================
        int t = 1e5;
        fout<<t<<endl;
        switch(_t)
        {
        case 1:
            for(int i=0;i<t;i++) fout<<rndupper()<<' '<<rndupper()<<rndupper()<<endl;
            break;
        case 2:
            for(int i=0;i<t;i++) fout<<rndupper()<<' '<<rndupper()<<rndelement()<<endl;
            break;
        case 3:
            for(int i=0;i<t;i++) fout<<rndelement()<<' '<<rndupper()<<rndelement()<<endl;
            break;
        case 4:
            for(int i=0;i<t;i++) fout<<rndelement()<<' '<<rndelement()<<rndelement()<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}
