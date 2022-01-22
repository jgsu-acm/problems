#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 10;
vector<int> v;
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        int n,m;
        n=m=2e5;
        fout<<n<<' '<<m<<endl;
        for(int i=1;i<=m;i++)
        {
            int opt = rnd(1,2)(egn),x,y;
            if(opt==1)
            {
                int f = rnd(0,1)(egn);
                if(f)
                {
                    x=v.empty()?rnd(1,n)(egn):v[rnd(0,v.size()-1)(egn)];
                y=v.empty()?rnd(1,n)(egn):v[rnd(0,v.size()-1)(egn)];
                }
                else 
                {
                    x=rnd(1,n)(egn);
                    y=rnd(1,n)(egn);
                }
            }
            else
            {
                x=v.empty()?rnd(1,n)(egn):v[rnd(0,v.size()-1)(egn)];
                y=v.empty()?rnd(1,n)(egn):v[rnd(0,v.size()-1)(egn)];
            }
            v.push_back(x);
            v.push_back(y);
            fout<<opt<<' '<<x<<' '<<y<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}