#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 10;
inline char rndchar() { return (char)(rnd('a','z')(egn)); }
#include <deque>
#include <algorithm>
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        int n = 1e7;
        fout<<n<<endl;
        while(n)
        {
            if(n==1) { fout<<rndchar(); break; }
            int p = rnd(1,100)(egn);
            if(p<=33)
            {
                int l;
                do l=rnd(1,n)(egn);
                while(l%2);
                n-=l;
                l/=2;
                string s;
                for(int i=0;i<l;i++)
                    s.push_back(rndchar());
                fout<<s;
                int p = rnd(1,100)(egn);
                if(p<=50) s.pop_back();
                reverse(s.begin(), s.end());
                fout<<s;
            }
            else if(p<=67)
            {
                int l;
                do l=rnd(1,rnd(1,n)(egn))(egn);
                while(l%2);
                n-=l;
                l/=2;
                string s;
                for(int i=0;i<l;i++)
                    s.push_back(rndchar());
                fout<<s;
                int p = rnd(1,100)(egn);
                if(p<=50) s.pop_back();
                reverse(s.begin(), s.end());
                fout<<s;
            }
            else 
            {
                int l = rnd(1,rnd(1,n)(egn))(egn);
                for(int i=0;i<l;i++)
                    fout<<rndchar();
                n-=l;
            }
        }
        // ==============================
        fout.close();
    }
    return 0;
}