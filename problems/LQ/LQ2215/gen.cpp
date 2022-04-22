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
        int n,ma,mb;
        if(_t==1)
        {
            n = 2;
            ma = rnd(1,8)(egn);
            mb = rnd(1,8)(egn);
        }
        else if(_t==2)
        {
            n = rnd(5,10)(egn);
            ma = mb = rnd(5,8)(egn);
        }
        else if(_t==3)
        {
            n = 10;
            ma = mb = 8;
        }
        else if(_t<=6)
        {
            n = rnd(2,1000)(egn);
            ma = rnd(9,1e5)(egn);
            mb = rnd(9,1e5)(egn);
        }
        else if(_t<=7)
        {
            n = 2;
            ma = rnd(9,1e5)(egn);
            mb = rnd(9,1e5)(egn);
        }
        else if(_t<=8)
        {
            n = rnd(2,1000)(egn);
            ma = mb = rnd(9,1e5)(egn);
        }
        else 
        {
            n = 1000;
            ma = mb = 1e5;
        }
        fout<<n<<endl;
        if(ma<mb) swap(ma, mb);
        vector<int> v1,v2;
        if(_t==2||_t==8)
        {
            int p = rnd(1,ma)(egn);
            for(int i=0;i<p;i++)
            {
                int t = rnd(0,n-1)(egn);
                v1.push_back(t);
                v2.push_back(t);
            }
            for(int i=0;i<ma-p;i++)
            {
                v1.push_back(rnd(0,n-1)(egn));
                v2.push_back(rnd(0,n-1)(egn));
            }
        }
        else 
        {
            for(int i=0;i<mb;i++)
            {
                int p = rnd(1,100)(egn);
                if(p<=30)
                {
                    v1.push_back(rnd(0,1)(egn));
                    v2.push_back(rnd(0,1)(egn));
                }
                else 
                {
                    v1.push_back(rnd(0,n-1)(egn));
                    v2.push_back(rnd(0,n-1)(egn));
                }
            }
            generate_n(inserter(v1,v1.end()), ma-mb, [n]() { return rnd(0,n-1)(egn); });
        }
        if(ma==mb)
        {
            for(int i=0;i<ma;i++)
            {
                if(v1[i]>v2[i]) break;
                if(v1[i]<v2[i])
                {
                    swap(v1[i], v2[i]);
                    break;
                }
            }
        }
        fout<<ma<<endl;
        for(auto i : v1) fout<<i<<' ';
        fout<<endl;
        fout<<mb<<endl;
        for(auto i : v2) fout<<i<<' ';
        fout<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}
