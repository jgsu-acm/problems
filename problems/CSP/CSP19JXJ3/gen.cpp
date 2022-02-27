#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 20;
#include <set>
typedef pair<int,int> pii;
set<pii> s;
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        if(t<=6)
        {
            int n,m;
            if(t>=5) n=m=15;
            else do n=rnd(1,15)(egn), m=rnd(1,15)(egn);
            while(n<2||m<2||m<n-1&&m>n*(n-1)/2);
            cout<<n<<' '<<m<<endl;
            for(int i=0;i<m;i++)
            {
                int u,v;
                do u=rnd(1,n)(egn), v=rnd(1,n)(egn);
                while(u==v||s.find({u,v})!=s.end()||s.find({v,u})!=s.end());
                s.insert({u,v}); s.insert({v,u});
                cout<<u<<' '<<v<<endl;
            }
            cout<<rnd(2,n)(egn)<<' '<<rnd(0,n)(egn)<<' '<<rnd(2,n)(egn)<<' '<<rnd(0,n)(egn)<<endl;
        }
        else if(t<=10)
        {
            int n;
            if(t>=8) n=100;
            else n = rnd(16,100)(egn);
            cout<<n<<' '<<n-1<<endl;
            for(int i=2;i<=n;i++)
                cout<<rnd(1, i-1)(egn)<<' '<<i<<endl;
            cout<<rnd(2,n)(egn)<<' '<<rnd(0,n)(egn)<<' '<<rnd(2,n)(egn)<<' '<<rnd(0,n)(egn)<<endl;
        }
        else
        {
            int n,m;
            do n=rnd(2,3000)(egn), m=rnd(2,3000)(egn);
            while(m<n-1&&m>n*(n-1)/2);
            cout<<n<<' '<<m<<endl;
            for(int i=0;i<m;i++)
            {
                int u,v;
                do u=rnd(1,n)(egn), v=rnd(1,n)(egn);
                while(u==v||s.find({u,v})!=s.end()||s.find({v,u})!=s.end());
                s.insert({u,v}); s.insert({v,u});
                cout<<u<<' '<<v<<endl;
            }
            int s = rnd(2,n)(egn);
            cout<<s<<' '<<rnd(0,n)(egn)<<' '<<s<<' '<<rnd(0,n)(egn)<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}