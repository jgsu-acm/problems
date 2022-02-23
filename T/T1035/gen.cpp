#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 10;
// ==============================
#include <string>
// ==============================
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        string s2;
        int len = rnd(1,10)(egn);
        for(int i=0;i<len;i++) s2.push_back((char)(rnd('A','Z')(egn)));
        string s1;
        while(s1.length()+s2.length()<=2e6)
        {
            int p = rnd(1,100)(egn);
            if(p<=10) s1.push_back((char)(rnd('A','Z')(egn)));
            else 
            {
                s1+=s2;
                if(p>=50) s1.back() = (char)(rnd('A','Z')(egn));
            }
        }
        fout<<s1<<endl<<s2<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}
