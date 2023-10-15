#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef uniform_int_distribution<> rnd;
typedef uniform_int_distribution<ll> rndll;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 4;
// ==============================

// ==============================
int main(int argc, char const* argv[])
{
    for(int _t=1;_t<=CASES;_t++)
    {
        ofstream fout(to_string(_t)+".in");
        // ==============================
        if(_t==1)
        {
            int t = 2e4;
            fout<<t<<endl;
            for(int s=0;s<t;s++)
            {
                int n = 10;
                fout<<n<<' '<<rnd(0,n)(egn)<<endl;
                for(int i=0;i<n;i++) fout<<rnd(1,100)(egn)<<" \n"[i==n-1];
                for(int i=0;i<n;i++) fout<<rnd(1,100)(egn)<<" \n"[i==n-1];
            }
        }
        else if(_t==2)
        {
            int t = 10;
            fout<<t<<endl;
            for(int s=0;s<t;s++)
            {
                int n = 2e4;
                fout<<n<<' '<<rnd(0,n)(egn)<<endl;
                for(int i=0;i<n;i++) fout<<rnd(1,100)(egn)<<" \n"[i==n-1];
                for(int i=0;i<n;i++) fout<<rnd(1,100)(egn)<<" \n"[i==n-1];
            }
        }
        else if(_t==3)
        {
            int t = 2e4;
            fout<<t<<endl;
            for(int s=0;s<t;s++)
            {
                int n = 10;
                fout<<n<<' '<<rnd(0,n)(egn)<<endl;
                for(int i=0;i<n;i++) fout<<rnd(1,1e9)(egn)<<" \n"[i==n-1];
                for(int i=0;i<n;i++) fout<<rnd(1,1e9)(egn)<<" \n"[i==n-1];
            }
        }
        else
        {
            int t = 10;
            fout<<t<<endl;
            for(int s=0;s<t;s++)
            {
                int n = 2e4;
                fout<<n<<' '<<rnd(0,n)(egn)<<endl;
                for(int i=0;i<n;i++) fout<<rnd(1,1e9)(egn)<<" \n"[i==n-1];
                for(int i=0;i<n;i++) fout<<rnd(1,1e9)(egn)<<" \n"[i==n-1];
            }
        }
        // ==============================
        fout.close();
    }
    return 0;
}
