#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef uniform_int_distribution<> rnd;
typedef uniform_int_distribution<ll> rndll;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 20;
// ==============================
const int mod = 1e9+7;
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
            do
            {
                ma = rnd(5,8)(egn);
                mb = rnd(5,8)(egn);
            } while(ma==mb);
        }
        else if(_t==2)
        {
            n = 2;
            ma = mb = rnd(5,8)(egn);
        }
        else if(_t<=4)
        {
            n = 10;
            ma = mb = 8;
        }
        else if(_t<=6)
        {
            n = 10;
            ma = rnd(5,8)(egn);
            mb = rnd(5,8)(egn);
        }
        else if(_t==7)
        {
            n = 2;
            do
            {
                ma = rnd(8e4,1e5)(egn);
                mb = rnd(8e4,1e5)(egn);
            } while(ma==mb);
        }
        else if(_t==8)
        {
            n = 2;
            ma = mb = rnd(8e4,1e5)(egn);
        }
        else if(_t<=10)
        {
            n = 1000;
            ma = mb = 1e5;
        }
        else
        {
            n = 1000;
            ma = rnd(8e4,1e5)(egn);
            mb = rnd(8e4,1e5)(egn);
        }
        fout<<n<<endl;
        if(ma<mb) swap(ma, mb);
        vector<int> v1,v2;
        if(_t==4||_t==10)
        {
            int x = rnd(1,n-1)(egn);
            v1.push_back(x);
            v2.push_back(x);
            for(int i=1;i<ma;i++)
            {
                x = rnd(0,n-1)(egn);
                v1.push_back(x);
                v2.push_back(x);
            }
        }
        else 
        {
            int x = rnd(1,n-1)(egn);
            int y = rnd(1,n-1)(egn);
            v1.push_back(x);
            v2.push_back(y);
            for(int i=1;i<mb;i++)
            {
                int p = rnd(1,100)(egn);
                if(p<=40)
                {
                    v1.push_back(rnd(0,1)(egn));
                    v2.push_back(rnd(0,n-1)(egn));
                }
                else if(p>60)
                {
                    v1.push_back(rnd(0,n-1)(egn));
                    v2.push_back(rnd(0,1)(egn));
                }
                else 
                {
                    v1.push_back(rnd(0,n-1)(egn));
                    v2.push_back(rnd(0,n-1)(egn));
                }
            }
            generate_n(inserter(v1,v1.end()), ma-mb, [n]() { return rnd(0,n-1)(egn); });
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
        }
        fout<<ma<<endl;
        for(auto i : v1) fout<<i<<' '; fout<<endl;
        fout<<mb<<endl;
        for(auto i : v2) fout<<i<<' '; fout<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}
