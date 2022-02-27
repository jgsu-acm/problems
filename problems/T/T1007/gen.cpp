#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 10;
#include <set>
#include <vector>
#include <algorithm>
#include <tuple>
typedef tuple<int,int,int> tp3;
vector<tp3> v;
set<pair<int,int>> edges;
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        int n=5e3, m=2e5;
        fout<<n<<' '<<m<<endl;
        if(t==3||t==5||t==7)
        {
            while(m--)
            {
                int x,y;
                do x=rnd(1,n/t)(egn),y=rnd(n/t,n-1)(egn);
                while(x==y||edges.find({x,y})!=edges.end()||edges.find({y,x})!=edges.end());
                edges.emplace(x,y);
                edges.emplace(y,x);
                fout<<x<<' '<<y<<' '<<rnd(1,1e4)(egn)<<endl;
            }
        }
        else 
        {
            v.clear();
            m-=(n-1);
            for(int i=2;i<=n;i++)
            {
                int fa = rnd(1,i-1)(egn);
                v.emplace_back(i, fa, rnd(1,1e4)(egn));
                edges.emplace(i,fa);
                edges.emplace(fa,i);
            }
            for(int i=0;i<m;i++)
            {
                int x,y;
                do x=rnd(1,n)(egn), y=rnd(1,n)(egn);
                while(x==y||edges.find({x,y})!=edges.end()||edges.find({y,x})!=edges.end());
                v.push_back({x,y,rnd(1,1e4)(egn)});
                edges.emplace(x,y);
                edges.emplace(y,x);
            }
            shuffle(v.begin(), v.end(), egn);
            for(auto [x,y,z] : v)
                fout<<x<<' '<<y<<' '<<z<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}