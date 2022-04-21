#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef uniform_int_distribution<> rnd;
typedef uniform_int_distribution<ll> rndll;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 10;
// ==============================
typedef tuple<int,int,int> tp3;
// ==============================
int main(int argc, char const* argv[])
{
    for(int _t=1;_t<=CASES;_t++)
    {
        ofstream fout(to_string(_t)+".in");
        // ==============================
        int n,m;
        if(_t<=4)
        {
            n = 1e3;
            m = 1e3-1;
        }
        else 
        {
            n = 5e4;
            m = 5e4-1;
        }
        fout<<n<<' '<<m<<endl;
        int maxx;
        switch(_t)
        {
        case 1: case 5: maxx = 1e4; break;
        case 2: case 6: maxx = 1e5; break;
        case 3: case 7: maxx = 1e6; break;
        case 4: case 8: maxx = 1e7; break;
        case 9: maxx = 1e7; break;
        case 10: maxx = 1e8; break;
        }
        vector<tp3> v1, v2;
        for(int i=0;i<n;i++)
        {
            int p = rnd(0,1)(egn);
            if(p&&i!=0)
            {
                auto [a,b,c] = v1[i-1];
                v1.emplace_back(a+rnd(-10,10)(egn), b+rnd(-10,10)(egn), rnd(5,10)(egn));
            }
            else v1.emplace_back(rnd(0,maxx)(egn), rnd(0,maxx)(egn), rnd(5,10)(egn));
        }
        for(int i=0;i<m;i++)
        {
            int p = rnd(0,1)(egn);
            if(p)
            {
                int p = rnd(0,n-1)(egn);
                auto [a,b,c] = v1[p];
                v2.emplace_back(a+rnd(-10,10)(egn), b+rnd(-10,10)(egn), rnd(5,10)(egn));
            }
            else v2.emplace_back(rnd(0,maxx)(egn), rnd(0,maxx)(egn), rnd(5,10)(egn));
        }
        for(auto [x,y,r] : v1) fout<<x<<' '<<y<<' '<<r<<endl;
        for(auto [x,y,r] : v2) fout<<x<<' '<<y<<' '<<r<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}
