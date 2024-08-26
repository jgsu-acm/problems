#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef uniform_int_distribution<> rnd;
typedef uniform_int_distribution<ll> rndll;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 20;
// ==============================

// ==============================
int main(int argc, char const* argv[])
{
    for(int _t=1;_t<=CASES;_t++)
    {
        ofstream fout(to_string(_t)+".in");
        // ==============================
        ll l,r;
        switch(_t)
        {
        case 1:
            fout<<"1 100000"<<endl;
            break;
        case 2:
            fout<<ll(1e9-1e5)<<' '<<ll(1e9)<<endl;
            break;
        case 3:
            fout<<"4413 104413"<<endl;
            break;
        case 4:
            fout<<"829352 929352"<<endl;
            break;
        case 5:
            fout<<"614967 714967"<<endl;
            break;
        case 6:
            fout<<"332616 432616"<<endl;
            break;
        case 7:
            fout<<"1575018021 1575118021"<<endl;
            break;
        case 8:
            fout<<ll(9999300000-1e5)<<' '<<9999300000<<endl;
            break;
        case 9:
            fout<<1<<' '<<ll(1e9)<<endl;
            break;
        case 10:
            fout<<ll(1e9)<<' '<<ll(2e9)<<endl;
            break;
        case 11:
            fout<<"785354403 1785354403"<<endl;
            break;
        case 12:
            fout<<"534090811 1534090811"<<endl;
            break;
        case 13:
            fout<<"716156955769 717156955769"<<endl;
            break;
        case 14:
            fout<<ll(1e12-1e9)<<' '<<ll(1e12)<<endl;
            break;
        case 15:
            fout<<"709665321377 710226935584"<<endl;
            break;
        case 16:
            fout<<"784741704584 785232113047"<<endl;
            break;
        case 17:
            fout<<"549280848351 549934074060"<<endl;
            break;
        case 18:
            fout<<"157128679432 157792007888"<<endl;
        case 19:
            fout<<"620730430055 621101189950"<<endl;
            break;
        case 20:
            fout<<"692739950722 693222271025"<<endl;
            break;
        }
        // ==============================
        fout.close();
    }
    return 0;
}
