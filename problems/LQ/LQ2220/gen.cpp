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
        int n;
        ll maxh;
        if(_t<=2)
        {
            n = 1000;
            maxh = 1e6;
        }
        else
        {
            n = 2e5;
            maxh = 1e18;
        }
        fout<<n<<endl;
        vector<ll> v;
        for(int i=0;i<n;i++)
        {
            int p = rnd(0,1)(egn);
            if(p||i==0) v.push_back(rndll(1,maxh)(egn));
            else
            {
                ll h = v[i-1];
                vector<ll> t;
                while(h>1)
                {
                    t.push_back(h);
                    h = sqrt(h/2+1);
                }
                if(t.empty()) v.push_back(rndll(1,maxh)(egn));
                else
                {
                    ll x = t.back()+1;
                    for(int j=0;j<rnd(4,5)(egn);j++)
                    {
                        if(x>sqrt(maxh)) break;
                        x *= x;
                    }
                    v.push_back(x+rnd(-100,100)(egn));
                }
            }
        }
        for(auto i : v) fout<<i<<' ';
        // ==============================
        fout.close();
    }
    return 0;
}
