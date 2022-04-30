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
        if(_t==2)
        {
            fout<<"2 1 2"<<endl;
            fout<<"1 2 0"<<endl;
        }
        else 
        {
            int n = 1e4;
            int m = 5e4;
            int k = _t;
            fout<<n<<' '<<m<<' '<<k<<endl;
            set<pair<int,int>> s;
            int last = 1;
            while(true)
            {
                int cur = last + rnd(1,100)(egn);
                if(cur>n) break;
                s.emplace(last, cur);
                last = cur;
            }
            if(last!=n) s.emplace(last, n);
            while(s.size()!=m)
            {
                int u,v;
                do
                {
                    u = rnd(1,n-1)(egn);
                    do v = u + rnd(1,100)(egn);
                    while(v>n);
                } while(u!=v&&s.find(make_pair(u,v))!=s.end()&&s.find(make_pair(v,u))!=s.end());
                s.emplace(u,v);
            }
            vector<pair<int,int>> v;
            copy(s.begin(),s.end(),inserter(v,v.begin()));
            shuffle(v.begin(), v.end(), egn);
            for(auto [x,y] : v) fout<<x<<' '<<y<<' '<<rnd(1,1e3)(egn)<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}
