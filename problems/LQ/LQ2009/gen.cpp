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
        int n = 100;
        bool flag = false;
        for(int i=0;i<n;i++)
        {
            int p = rnd(1,100)(egn);
            if(flag&&p<=50)
            {
                fout<<rnd(2,9)(egn);
                flag = false;
            }
            else
            {
                if(p<=50) fout<<char(rnd('a', 'z')(egn));
                else fout<<char(rnd('A','Z')(egn));
                flag = true;
            }
        }
        // ==============================
        fout.close();
    }
    return 0;
}
