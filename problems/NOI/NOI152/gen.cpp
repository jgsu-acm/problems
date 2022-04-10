#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef uniform_int_distribution<> rnd;
typedef uniform_int_distribution<ll> rndll;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 20;
// ==============================

// ==============================
int main(int argc, char const* argv[])
{
    for(int _t=1;_t<=CASES;_t++)
    {
        ofstream fout(to_string(_t)+".in");
        // ==============================
        if(_t<=2)
        {
            int n = 5000;
            int q = 5000;
            fout<<n<<endl;
            if(_t==1)
            {
                for(int i=1;i<n;i++) fout<<rnd(0,i-1)(egn)<<' ';
                fout<<endl;
                fout<<q<<endl;
                for(int i=0;i<q;i++) fout<<(rnd(0,1)(egn)?"install":"uninstall")<<' '<<rnd(0,n-1)(egn)<<endl;
            }
            else 
            {
                fout<<0<<' ';
                for(int i=2;i<n;i++) fout<<rnd(i-2,i-1)(egn)<<' ';
                fout<<endl;
                fout<<q<<endl;
                for(int i=0;i<q;i++) fout<<(rnd(0,1)(egn)?"install":"uninstall")<<' '<<rnd(n/10*9,n-1)(egn)<<endl;
            }
        }
        else 
        {
            int n = 1e5;
            int q = 1e5;
            fout<<n<<endl;
            if(_t<=4)
            {
                for(int i=1;i<n;i++) fout<<rnd(0,i-1)(egn)<<' ';
                fout<<endl;
                fout<<q<<endl;
                for(int i=0;i<q;i++) fout<<"install "<<rnd(0,n-1)(egn)<<endl;
            }
            if(_t<=6)
            {
                fout<<0<<' ';
                for(int i=2;i<n;i++) fout<<rnd(i-2,i-1)(egn)<<' ';
                fout<<endl;
                fout<<q<<endl;
                for(int i=0;i<q;i++) fout<<"install "<<rnd(n/10*9,n-1)(egn)<<endl;
            }
            else if(_t<=8)
            {
                for(int i=1;i<n;i++) fout<<rnd(0,i-1)(egn)<<' ';
                fout<<endl;
                fout<<q<<endl;
                for(int i=0;i<q;i++) fout<<(rnd(0,1)(egn)?"install":"uninstall")<<' '<<rnd(0,n-1)(egn)<<endl;
            }
            else
            {
                fout<<0<<' ';
                for(int i=2;i<n;i++) fout<<rnd(i-2,i-1)(egn)<<' ';
                fout<<endl;
                fout<<q<<endl;
                for(int i=0;i<q;i++) fout<<(rnd(0,1)(egn)?"install":"uninstall")<<' '<<rnd(n/10*9,n-1)(egn)<<endl;
            }
        }
        // ==============================
        fout.close();
    }
    return 0;
}
