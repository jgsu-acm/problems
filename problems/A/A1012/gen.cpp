#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 100;
string yw = "\
0001000\n\
0001000\n\
0011100\n\
0011100\n\
0000000\n\
0000000\n\
0000000";
string gj = "\
0000000\n\
0001000\n\
0011100\n\
0111110\n\
0011100\n\
0001000\n\
0000000";
string js = "\
0000000\n\
0000000\n\
0001000\n\
0001000\n\
0000000\n\
0000000\n\
0000000";
string lsl = "\
0000000\n\
0000000\n\
0001000\n\
0011100\n\
0000000\n\
0000000\n\
0000000";
string zz = "\
0000000\n\
0000000\n\
0000000\n\
0001000\n\
0000000\n\
0000000\n\
0000000";
string yh = "\
0001000\n\
0011100\n\
0111110\n\
1111111\n\
0000000\n\
0000000\n\
0000000";
string sc = "\
0000000\n\
0111110\n\
0011100\n\
0001000\n\
0000000\n\
0000000\n\
0000000";
string sr = "\
0000000\n\
0001000\n\
0001000\n\
0001000\n\
0000000\n\
0000000\n\
0000000";
string sj = "\
0011100\n\
0011100\n\
0011100\n\
0011100\n\
0000000\n\
0000000\n\
0000000";
string zj = "\
0000000\n\
0011100\n\
0011100\n\
0011100\n\
0000000\n\
0000000\n\
0000000";
vector<string> v = {yw,gj,js,lsl,zz,yh,sc,sr,sj,zj};
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        fout<<v[rnd(0,v.size()-1)(egn)]<<endl;
        int n = rnd(3,10)(egn);
        fout<<n<<endl;
        for(int i=0;i<n;i++)
            fout<<rnd(1,10)(egn)<<' '<<rnd(1,10)(egn)<<' '<<rnd(1,4)(egn)<<endl;
        // ==============================
        fout.close();
    }
    return 0;
}