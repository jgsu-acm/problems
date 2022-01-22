#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 10;
#include <vector>
#include <string>
const vector<string> s = {
    "red","puple","blue","black","green","yellow","grey","while","orange","brown"
};
const vector<string> r = {
    "aaa","bbb","ccc","abc","asd","qwq","qaq","sto","orz","none"
};
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        int n = 2e5;
        fout<<n<<endl;
        if(t==10)
        {
            for(int i=0;i<n;i++)
                fout<<s[i%2]<<endl;
            continue;
        }
        for(int i=0;i<n;i++)
        {
            int p = rnd(1,100)(egn);
            if(p<=33) fout<<s[rnd(0,s.size()-1)(egn)]<<endl;
            else if(p<=66) fout<<r[rnd(0,r.size()-1)(egn)]<<endl;
            else
            {
                int l = rnd(1,10)(egn);
                for(int i=0;i<l;i++) fout<<(char)(rnd(0,25)(egn)+'a');
                fout<<endl;
            }
        }
        // ==============================
        fout.close();
    }
    return 0;
}