#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 20;
// ==============================

// ==============================
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        auto hack1 = [](int n)
        {
            int cnt = 0;
            for(int i=1;i<n;i++) if(i*i%n<n/2) cnt++;
            return cnt;
        };
        auto hack2 = [](int n)
        {
            int cnt = 0;
            for(int i=1;i<n;i++) if(i*i%n<=n/2.0) cnt++;
            return cnt;
        };
        auto correct = [](int n)
        {
            int cnt = 0;
            for(int i=1;i<n;i++) if(i*i%n<n/2.0) ++cnt;
            return cnt;
        };
        int n;
        if(t<=CASES/2)
        {
            while(true)
            {
                n = rnd(1,1000)(egn);
                int x = hack1(n);
                int c = correct(n);
                if(x!=c) break;
            }
        }
        else
        {
            while(true)
            {
                n = rnd(1,1000)(egn);
                int x = hack2(n);
                int c = correct(n);
                if(x!=c) break;
            }
        }
        fout<<n<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}
