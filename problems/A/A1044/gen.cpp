#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef uniform_int_distribution<> rnd;
typedef uniform_int_distribution<ll> rndll;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 7;
// ==============================
string t;
vector<string> v;
const string m = "XO.";
void dfs(int x)
{
    if(!x)
    {
        v.emplace_back(t);
        return;
    }
    for(char c : m)
    {
        t.push_back(c);
        dfs(x - 1);
        t.pop_back();
    }
}
// ==============================
int main(int argc, char const* argv[])
{
    for(int _t=1;_t<=CASES;_t++)
    {
        ofstream fout(to_string(_t)+".in");
        // ==============================
        auto output = [&](const string& x)
        {
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++) fout<<x[i*3+j];
                fout<<endl;
            }
        };
        switch(_t)
        {
        default:
            dfs(9);
            fout<<v.size()<<endl;
            for(auto& x : v) output(x);
            break;
        case 1:
            fout<<1<<endl;
            output("XXXOO....");
            break;
        case 2:
            fout<<1<<endl;
            output("OX.XO.X.O");
            break;
        case 3:
            fout<<1<<endl;
            output(".........");
            break;
        case 4:
            fout<<1<<endl;
            output("........X");
            break;
        case 5:
            fout<<1<<endl;
            output("........O");
            break;
        case 6:
            fout<<1<<endl;
            output("XOXOOXXXO");
            break;
        }
        // ==============================
        fout.close();
    }
    return 0;
}
