#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 25;
#include <set>
set<int> s;
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        int n,m,maxL;
        if(t<=3) n=rnd(1,10)(egn), m=rnd(1,10)(egn), maxL=10;
        else if(t<=6) n=rnd(11,100)(egn), m=rnd(11,100)(egn), maxL=1000;
        else if(t<=8) n=m=100, maxL=1000;
        else if(t<=11) n=rnd(101,1000)(egn), m=rnd(101,1000)(egn), maxL=1e9;
        else if(t<=13) n=m=1000, maxL=1e9;
        else if(t<=16) n=rnd(1001,1e4)(egn), m=rnd(1001,1e4)(egn), maxL=1e9;
        else if(t<=18) n=m=1e4, maxL=1e9;
        else if(t<=23) n=rnd(1e4+1,2e5)(egn), m=rnd(1e4+1,2e5)(egn), maxL=1e9;
        else n=m=2e5, maxL=1e9;
        int L;
        do L=rnd(1,maxL)(egn);
        while(L<m);
        fout<<n<<' '<<m<<' '<<L<<endl;
        while(s.size()<m-1)
            s.insert(rnd(1,L-1)(egn));
        for(auto i : s) fout<<i<<' ';
        fout<<endl;
        for(int i=0;i<m;i++) fout<<rnd(1,n)(egn)<<' ';
        fout<<endl;
        for(int i=0;i<n;i++)
        {
            int s;
            if(14<=t&&t<=18) s=0;
            else s=rnd(0,1)(egn);
            fout<<s<<' '<<rnd(0, L-1)(egn)<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}