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
        int n;
        switch(_t)
        {
        case 1: n = rnd(1,15)(egn); break;
        case 2: n = 15; break;
        case 3: case 4: case 5: n = rnd(16,100)(egn); break;
        case 6: n = 100; break;
        case 7: n = rnd(101,1000)(egn); break;
        case 8: n = 1000; break;
        case 9: n = rnd(1001, 1e5)(egn); break;
        case 10: n = 1e5; break;
        }
        fout<<n<<endl;
        generate_n(ostream_iterator<int>(fout, " "), n, []() { return rnd(1,1000)(egn); });
        // ==============================
        fout.close();
    }
    return 0;
}
