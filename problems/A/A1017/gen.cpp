#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 10;
bool mp[1005][1005];
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        int n = 500;
        fout<<n<<endl;
        int m = rnd(1, n*n)(egn);
        if(t>=8) m=n*n;
        fout<<m<<endl;
        while(m--)
        {
            int x,y;
            do x=rnd(1,n)(egn), y=rnd(1,n)(egn);
            while(mp[x][y]);
            mp[x][y]=true;
            fout<<x<<' '<<y<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}